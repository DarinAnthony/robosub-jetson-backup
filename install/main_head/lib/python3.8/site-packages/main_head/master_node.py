import rclpy
from rclpy.node import Node
from interfaces.srv import StartRoutine
from geometry_msgs.msg import Twist
import time


kNoTwist = Twist()
kGoDownTwist = Twist()
kGoDownTwist.linear.z = -0.5
# kGoDownTwist.angular.y = -0.7

kGoForwardStayDownTwist = Twist()
kGoForwardStayDownTwist.linear.z = -0.25
kGoForwardStayDownTwist.linear.x = 0.5

kJustHold = Twist()
kJustHold.linear.z = -0.25
# kGoForwardStayDownTwist.angular.y = -0.7
# kGoForwardStayDownTwist.angular.z = 0.1


kGoUpTwist = Twist()
kGoUpTwist.linear.z = 0.5

class MasterNode(Node):
    def __init__(self):
        super().__init__('master_node')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.pub_timer = self.create_timer(0.1, self.timer_callback)
        self.startsrv = self.create_service(StartRoutine, 'start_routine', self.start_routine)
        self.start = False
        self.start_time = time.time()
        self.runs = 4
        self.run = 0


    def start_routine(self, request, response):
        if request.start:
            self.start = True
            self.start_time = time.time()
            self.get_logger().info('Starting!')
        response.success = True
        return response

    def timer_callback(self):
        if not self.start:
            self.pub.publish(kNoTwist)
            self.get_logger().info('Don\'t start!')
            return
        self.get_logger().info('going')
        self.pub.publish(self.get_twist())
    
    def get_twist(self) -> Twist:
        now = time.time()
        time_passed = now - self.start_time
        if self.run == 0:
            if time_passed < 5:
                return kGoDownTwist
            else:
                self.start_time = time.time()
                self.run += 1
        if self.run < self.runs + 1:
            now = time.time()
            time_passed = now - self.start_time
            if time_passed < 4:
                return kGoForwardStayDownTwist
            elif time_passed < 9:
                return kJustHold
            elif time_passed < 13:
                return kGoForwardStayDownTwist
            elif time_passed < 18:
                return kJustHold
            else:
                self.start_time = time.time()
                self.run += 1
                return kNoTwist
        now = time.time()
        time_passed = now - self.start_time   
        if time_passed < 5:
            return kGoUpTwist
        self.start = False
        self.run = 0
        return kNoTwist
            


def main(args=None):
    rclpy.init(args=args)
    master_node = MasterNode()
    rclpy.spin(master_node)
    rclpy.shutdown()
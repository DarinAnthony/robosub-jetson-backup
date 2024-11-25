# Node that subscribes to /joy message and publishes a twist to /cmd_vel
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

class JoyToTwist(Node):
    def __init__(self):
        super().__init__('joy_to_twist')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription_ = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

    def joy_callback(self, msg):
        twist = Twist()
        twist.linear.x = msg.axes[0]  # move forward/backward
        twist.linear.y = msg.axes[1]  # move forward/backward
        twist.linear.z = msg.axes[2]  # move forward/backward
        twist.angular.x = msg.axes[3]  # turn left/right
        twist.angular.y = msg.axes[4]  # turn left/right
        twist.angular.z = msg.axes[5]  # turn left/right
        self.publisher_.publish(twist)
        print('publishing twist: ', twist)

def main(args=None):
    rclpy.init(args=args)
    node = JoyToTwist()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

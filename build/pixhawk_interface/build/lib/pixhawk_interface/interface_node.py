# Create a new file pixhawk_controller.py PixhawkController class with abstractions for the mavlink calls
# Subscribes to /cmd_vel
# Arm / disarm service
# publishes whatever sensors are connected to the pixhawk
import rclpy
from rclpy.node import Node
from interfaces.srv import ArmPixhawk, DisarmPixhawk
from . import pixhawk_controller
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Twist
from interfaces.msg import Attitude
from . import pixhawk_controller
from . import data_class


class PixhawkInterfaceNode(Node):
    def __init__(self) -> None:
        super().__init__('PixhawkInterfaceNode')
        self.pixhawk = pixhawk_controller.PixhawkInterface()
        self.armsrv = self.create_service(
            ArmPixhawk, 'arm_pixhawk', self.arm_pixhawk_cb)
        self.disarmsrv = self.create_service(
            DisarmPixhawk, 'disarm_pixhawk', self.disarm_pixhawk_cb)

        self.manual_sub = self.create_subscription(
            Twist, '/cmd_vel', self.manual_control, 10)
        self.attitude_publisher = self.create_publisher(
            Attitude, 'attitude', 10)
        self.gyro_publisher = self.create_publisher(Imu, 'gyro', 10)
        self.timer = self.create_timer(0.5, self.timer_callback)
        self.datatypes = {
            'attitude': ('ATTITUDE', data_class.attitude, self.attitude_publisher),
            'gyro': ('SCALED_IMU', data_class.imu, self.gyro_publisher),
        }
        self.get_logger().info('Interface node started!')

    def arm_pixhawk_cb(self, request, response):
        print('arming pixhawk')
        response.success = False
        self.pixhawk.arm()
        self.pixhawk.wait_for_arm()
        response.success = True
        return response

    def disarm_pixhawk_cb(self, request, response):
        print('disarming pixhawk')
        response.success = False
        self.pixhawk.disarm()
        self.pixhawk.wait_for_disarm()
        response.success = True
        return response

    def timer_callback(self):
        for k, v in self.datatypes.items():
            raw_msg = self.pixhawk.get_data(v[0])

            if raw_msg != None:
                ros_msg = v[1](raw_msg.to_dict())
                v[2].publish(ros_msg)
                # self.get_logger().info('publishing %s: %s' % (k, ros_msg))
            else:
                pass
                # print("%s data not available!" % k)

    def manual_control(self, twist: Twist):
        self.pixhawk.manual_control(
            [twist.linear.x, twist.linear.y, twist.linear.z,
             twist.angular.x, twist.angular.y, twist.angular.z])


def main(args=None):
    rclpy.init(args=args)
    pixhawk_interface_node = PixhawkInterfaceNode()
    rclpy.spin(pixhawk_interface_node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

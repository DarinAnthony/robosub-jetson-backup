from . import dvl
import logging
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3Stamped
from . import parsing
import time

PORT = '/dev/ttyUSB0'
BAUD = 9600


class DVLDriverNode(Node):
    def __init__(self):
        super().__init__('dvl_driver_node')
        self.explorer = dvl.ExplorerDVL(
            port='/dev/ttyUSB0', baudrate=9600, loglevel=logging.DEBUG, headerparser=parsing.header_to_parser)
        self.timer = self.create_timer(0.01, self.update_explorer)
        self.explorer.config()
        self.explorer.wait_for_line()
        self.explorer.begin_pinging()
        self.btm_pub = self.create_publisher(Vector3Stamped, '/edvl/bottomtrack', 10)

    def update_explorer(self):
        self.explorer.update()
        vctr = Vector3Stamped()
        if self.explorer.bottomtrackhighres != None:
            vctr.header.stamp = self.get_clock().now().to_msg()
            vctr.vector.x = self.explorer.bottomtrackhighres.x
            vctr.vector.y = self.explorer.bottomtrackhighres.y
            vctr.vector.z = self.explorer.bottomtrackhighres.z
        self.btm_pub.publish(vctr)


def main(args=None):
    rclpy.init(args=args)
    dvl_node = DVLDriverNode()
    rclpy.spin(dvl_node)
    dvl_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

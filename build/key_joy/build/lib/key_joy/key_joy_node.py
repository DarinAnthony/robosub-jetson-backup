import sys
from select import select
import time
from . import key_parser

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy


class KeyJoyNode(Node):
    def __init__(self, key_settings):
        super().__init__('KeyJoyNode')
        self.publisher_ = self.create_publisher(Joy, '/joy', 10)
        self.timer_ = self.create_timer(0.1, self.timer_callback)
        self.last_msg_ = Joy()
        self.key_settings = key_settings
        self.not_quit = True

    def timer_callback(self):
        
        key = key_parser.get_key(self.key_settings)
        msg = Joy()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.axes = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        msg.buttons = [0, 0, 0, 0, 0, 0, 0, 0]

        if key == 'w':
            msg.axes[1] = 0.5
        elif key == 's':
            msg.axes[1] = -0.5
        elif key == 'a':
            msg.axes[0] = -0.5
        elif key == 'd':
            msg.axes[0] = 0.5
        elif key == 'q':
            msg.axes[2] = 0.5
        elif key == 'e':
            # msg.axes[2] = -0.24
            # msg.axes[0] = 0.3
            msg.axes[4] = 0.3
        elif key == 'p':
            self.not_quit = False
        if msg != self.last_msg_:
            self.publisher_.publish(msg)
            self.last_msg_ = msg


def main(args=None):
    terminal_settings = key_parser.save_terminal_settings()
    rclpy.init(args=args)
    node = KeyJoyNode(terminal_settings)
    while node.not_quit:
        rclpy.spin_once(node)
    node.destroy_node()
    rclpy.shutdown()
    key_parser.restore_terminal_settings(terminal_settings)


if __name__ == '__main__':
    main()

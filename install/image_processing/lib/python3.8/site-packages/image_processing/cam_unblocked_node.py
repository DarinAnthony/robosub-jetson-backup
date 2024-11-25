import rclpy
import rclpy.node
import cv2
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from interfaces.srv import StartRoutine

class CamUnblocked(rclpy.node.Node):
    def __init__(self):
        super().__init__('image_reader')
        self.sub = self.create_subscription(Image, '/camera0/image_raw', self.has_unblocked, 10)
        self.cli = self.create_client(StartRoutine, 'start_routine')
        self.br = CvBridge()


    def has_unblocked(self, img: Image):
        self.get_logger().info('Receiving video frame')
        current_frame = np.asarray(self.br.imgmsg_to_cv2(img))
        if np.average(current_frame) > 50:
            req = StartRoutine.Request()
            req.start = True
            self.cli.call(req)

def main(args=None):
    rclpy.init(args=args)
    cam_unblocked = CamUnblocked()
    rclpy.spin(cam_unblocked)
    cam_unblocked.destroy_node()

    rclpy.shutdown()


if __name__ == 'main':
    main()
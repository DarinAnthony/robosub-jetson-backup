import rclpy
import rclpy.node
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

class ImageReader(rclpy.node.Node):
    def __init__(self):
        super().__init__('image_reader')
        self.sub = self.create_subscription(Image, '/camera0/image_raw', self.display_image, 10)
        self.br = CvBridge()


    def display_image(self, img: Image):
        self.get_logger().info('Receiving video frame')
        current_frame = self.br.imgmsg_to_cv2(img)
        cv2.imshow('framex', current_frame)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    image_reader = ImageReader()
    rclpy.spin(image_reader)
    image_reader.destroy_node()

    rclpy.shutdown()


if __name__ == 'main':
    main()
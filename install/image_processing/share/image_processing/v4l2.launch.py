from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    descs = [
        Node(package='image_processing',
             executable='cam_unblocked_node'),
        Node(package='v4l2_camera', 
             namespace='camera0',
             executable='v4l2_camera_node', 
             name='explorerHD',
             parameters=[{'video_device':'/dev/video2'}, {'image_size':[1920,1080]}])
    ]
    return LaunchDescription(descs)

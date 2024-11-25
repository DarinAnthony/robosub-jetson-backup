import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='main_head',
            executable='master_node',
            name='master_node'),
        launch_ros.actions.Node(
            package='pixhawk_interface',
            executable='interface_node',
            name='interface_node'),       
  ])

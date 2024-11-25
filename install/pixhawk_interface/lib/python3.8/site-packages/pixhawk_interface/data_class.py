from typing import Any
from sensor_msgs.msg import Imu
from interfaces.msg import Attitude

def attitude(msg):
    time_stamp = msg["time_boot_ms"]
    body_rotation = (msg["roll"], msg["pitch"], msg["yaw"])
    rotating_speed = (msg["rollspeed"], msg["pitchspeed"], msg["yawspeed"])

    ros2_msg = Attitude()

    # rotation in rad (Range:[-pi, pi])
    ros2_msg.roll, ros2_msg.pitch, ros2_msg.yaw = body_rotation

    # rotation speed in rad/s
    ros2_msg.rollspeed, ros2_msg.pitchspeed, ros2_msg.yawspeed = rotating_speed

    return ros2_msg
    
def imu(msg):
    time_stamp = msg["time_boot_ms"]
    # x, y, z in mrad/s
    angular_speed = (msg["xgyro"], msg["ygyro"], msg["zgyro"])
    # x, y, z in mG
    acceleration = (msg["xacc"], msg["yacc"], msg["zacc"])

    ros2_msg = Imu()

    # no estimate for orientation in Quaternion
    ros2_msg.orientation_covariance[0] = -1

    # Angular velocity in rad/s (x, y, z)
    msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z \
        = tuple(ele/1000 for ele in angular_speed)
    
    # Linear acceleration in m/s^2 (x, y, z)
    msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z \
        = tuple(ele/1000*9.81 for ele in acceleration)
    
    return ros2_msg
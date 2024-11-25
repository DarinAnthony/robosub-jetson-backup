from pymavlink import mavutil
from typing import List
import time


class PixhawkInterface:
    def __init__(self, ip='192.168.2.1') -> None:
        self.master = mavutil.mavlink_connection(f'udpin:{ip}:14550')
        # self.master = mavutil.mavlink_connection("/dev/ttyACM0", baud=9600)
        self.master.wait_heartbeat()
        print('Connected to Pixhawk')
        self.master.mav.request_data_stream_send(
            self.master.target_system,
            self.master.target_component,
            0,
            100,  # 100 Hz
            1,  # start sending
        )

    def arm(self):
        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            1, 0, 0, 0, 0, 0, 0)

    def disarm(self):
        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            0, 0, 0, 0, 0, 0, 0)

    def wait_for_disarm(self):
        self.master.motors_disarmed_wait()

    def wait_for_arm(self):
        self.master.motors_armed_wait()

    def manual_control(self, sixd: List[float]):
        '''
        x,y,z linear
        x,y,z angular
        '''
        self.master.mav.manual_control_send(
            self.master.target_system,
            int(sixd[0] * 1000),
            int(sixd[1] * 1000),
            int(sixd[2] * 500 + 500),  # 0-1000
            int(sixd[5] * 1000), # yaw (z angular)
            0, 
            0
        )

    def request_param(self, param_id: str):
        param_bytes = bytes(param_id)
        self.master.mav.param_request_read_send(
            self.master.target_system, self.master.target_component,
            param_bytes,
            -1
        )
        message = self.master.recv_match(
            type='PARAM_VALUE', blocking=True).to_dict()['param_value']
        return message

    def get_data(self, data_type: str):
        msg = self.master.recv_match(type=data_type, blocking=False)
        return msg

    def calibrate(self, sensor: str):
        param1, param2, param3, param4, param5, param6, param7 = \
            0, 0, 0, 0, 0, 0, 0

        if sensor == "gyro":
            param1 = 1  # gyro calibration
        elif sensor == "accelerometer":
            param5 = 4  # simple accelerometer calibration w/o rotation
        elif sensor == "level":
            param5 = 2  # level horizon calibration
        elif sensor == "magnetometer":
            param2 = 1  # magnetometer calibration
        else:
            return False

        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_PREFLIGHT_CALIBRATION,
            0,
            param1, param2, param3, param4, param5, param6, param7)

        feedback = self.master.recv_match(type='COMMAND_ACK', blocking=True)
        if feedback.result != 0:
            return False
        time.sleep(5)  # Allow at least 5s for completing calibration
        return True

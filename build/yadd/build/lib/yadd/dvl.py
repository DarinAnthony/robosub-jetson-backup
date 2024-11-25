import serial
import sys
import time
from . import commands
import struct
from typing import List
import logging

_checksumConstant = 0xFFFF
_headerDataByte = b'\x7f'
START_LINE = b'>'
PING_CMD_S = 'CS'
CR = '\r'



class ExplorerDVL():
    '''ExplorerDVL, implements serial connection to the DVL
    need to call 
    dvl.config()
    dvl.wait_for_line()
    dvl.begin_pinging()

    after this you call dvl.update() in a loop. 
    And depending on the dvl configuration, there will be different attributes
    you can access.
    The names of the attributes are defined in headerparser, which is a dictionatry
    of header in bytes: int -> (attributename: str, parser function: )

    so after calling update, if any attributees with 'header in bytes' are found in
    the ensemble, they will be parsed and the parsed information will be stored in 
    the dvl.attributename which you can access after the first update. the attributes
    will be set to None if the were never updated
    '''
    def __init__(self, port='/dev/ttyUSB0', baudrate=9600, loglevel=logging.CRITICAL, headerparser=None):
        self.port = port
        self.baudrate = baudrate
        self.logger = logging.Logger('ExplorerDVL', loglevel)
        self.headerparser = {} if headerparser is None else headerparser

        for k,v in self.headerparser.items():
            setattr(self, v.name, None)

        try:
            self.conn = serial.Serial(self.port, self.baudrate)
        except Exception as e:
            self.logger.critical(e.__str__())
            print(e)
            sys.exit(1)

    def send_command(self, cmd: str):
        self.conn.write((''.join([cmd, CR]).encode('ascii')))

    def wait_for_line(self):
        while (self.conn.read(1) != START_LINE):
            time.sleep(0.01)

    def send_break_command(self):
        self.send_command('===')

    def disconnect(self):
        self.conn.close()

    def send_commands(self, commands: List[str]):
        commands_str = '\r'.join(commands)
        self.send_command(commands_str)

    def begin_pinging(self):
        self.send_command('CS\r')

    def config(self):
        self.send_break_command()
        self.wait_for_line()
        self.send_commands(commands.setup_commands)
    
    def disconnect_serial(self):
        self.conn.close()

    def update(self):
        bytes_read = 0
        print(f'Scanning for ensemble')
        # garbage data until start of header
        self.conn.read_until(b'\x7f\x7f')
        bytes_read += 2
        print(f'Found')

        ensemble_length = int.from_bytes(
            self.conn.read(2), 'little')  # LSB first
        bytes_read += 2
        print(f'Ensemble Length: {ensemble_length}')

        # endianness doesn't matter for 1 byte
        spare = int.from_bytes(self.conn.read(1), 'little')
        bytes_read += 1

        # endianness doesn't matter for 1 byte
        num_types = int.from_bytes(self.conn.read(1), 'little')
        bytes_read += 1
        print(f'Number of types: {num_types}')

        offsets_b = self.conn.read(num_types * 2)  # 2 bytes per data type
        bytes_read += num_types * 2

        # < means little endian, H means unsigned short. There should be num_types little endian, unsigned shorts
        offsets = struct.unpack('<' + ''.join(['H'] * num_types), offsets_b)
        

        left_to_read = ensemble_length - bytes_read
        beginning = bytes_read

        rest_of_packet = self.conn.read(left_to_read)
        bytes_read += left_to_read

        # add 1 to get ensemble byte offset for datatype i, pp. 177, subtract 
        # beginning because our rest_of_packet doesn't have all the stuff we 
        # read from serial up to now
        offsets = [i-beginning for i in offsets]
        print(f'Offsets: {offsets}')
        data = []
        for i in range(len(offsets)-1):
            data.append(rest_of_packet[offsets[i]:offsets[i+1]])
        data.append(rest_of_packet[offsets[-1]:-2])
        checksum = rest_of_packet[-2:]
        for t in data:
            print(f'first bytes are: {t[1:2].hex()}{t[0:1].hex()}')
            header = int.from_bytes(t[0:2], 'little')
            if header not in self.headerparser:
                # print('skipping')
                continue
            # print(f'length of data: {len(t)}')
            # print(f'headher: {header}')
            print(f'parsing: {t.hex(sep=" ")}')
            parsed = self.headerparser[header].parse(t)
            name = self.headerparser[header].name
            setattr(self, name, parsed)

                
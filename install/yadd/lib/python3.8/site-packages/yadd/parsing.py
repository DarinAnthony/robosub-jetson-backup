import struct
from dataclasses import dataclass
from typing import Callable
from . import dataformats

fixed_leader_format = '<HccHccccHHHccccHccccHHccHHHccHQHccI'
fixed_leader_header = b'\x00\x00'
variable_leader_format = '<HHccccccccHHHHHHHHccccccccccccccIHIII'
variable_leader_header = b'\x00\x80'

def getparserfunc(formatstr: str, clas: type):
    return lambda buffer: clas(struct.unpack(formatstr, buffer))

@dataclass
class NameParser():
    name: str
    parse: Callable

bottomtrackheader = int.from_bytes(b'\x58\x03', 'big')
bottom_track_parser = getparserfunc(formatstr='<Hiiiiiiiiiiiiiiiii', clas=dataformats.BottomTrackHighResolution)
header_to_parser = {
    bottomtrackheader: NameParser(name="bottomtrackhighres", parse=bottom_track_parser)
}




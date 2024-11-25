from . import utils

POINT_01_MM_TO_MM = 100.0

class BottomTrackHighResolution():
	def __init__(self, data):
		self.data = data
		print(f'parsed: data: {data}')
		self._y = 0
		self._x = 0
		self._z = 0
		self._parse() # parses x,y,z
	
	def _parse(self):
		self._y = utils.mmps_to_mps(self.data[1]/POINT_01_MM_TO_MM)
		self._x = utils.mmps_to_mps(self.data[2]/POINT_01_MM_TO_MM)
		self._z = utils.mmps_to_mps(self.data[3]/POINT_01_MM_TO_MM)

	@property
	def y(self) -> float:
		'''Velocity in the Y direction in m/s, depends config of dvl
		'''
		return self._y
	
	@property
	def z(self) -> float:
		'''Velocity in the Z direction in m/s, depends config of dvl
		'''
		return self._z

	@property
	def x(self) -> float:
		'''Velocity in the X direction in m/s, depends config of dvl
		'''
		return self._x
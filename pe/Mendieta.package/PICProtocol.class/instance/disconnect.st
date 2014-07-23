connection
disconnect
	self isConnected ifTrue: [
		self hid close: device.
		device := nil]
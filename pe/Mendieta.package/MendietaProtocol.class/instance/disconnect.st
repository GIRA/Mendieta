connection
disconnect
	self isConnected ifFalse: [^ self].
	self stopStepping.
	self hid close: device.
	device := nil
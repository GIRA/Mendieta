connection
connect
	self isConnected ifTrue: [^ self].
	device := [self hid open: 16r04D8 with: 16r003F]
			on: Error do: [nil].
	device notNil ifTrue: [self startStepping]
	
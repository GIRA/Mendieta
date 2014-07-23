connection
connect
	self isConnected ifTrue: [self disconnect].
	device := self hid open: 16r04D8 with: 16r003F.
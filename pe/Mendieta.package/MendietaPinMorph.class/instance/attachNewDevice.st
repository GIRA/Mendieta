attaching
attachNewDevice
	| newDevice |
	newDevice := self newDevice.
	newDevice isNil ifTrue: [self borderWidth: 0. ^ self].
	newDevice center: self center.
	newDevice openInWorld.
	self attach: newDevice
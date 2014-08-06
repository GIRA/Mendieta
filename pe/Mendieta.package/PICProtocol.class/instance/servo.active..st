commands
servo: pin active: val
	self send:	{self class rqServoActive.
				pin.
				val}
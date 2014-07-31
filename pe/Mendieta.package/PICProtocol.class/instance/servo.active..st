commands
servo: pin active: val
	self send:	{self class rqActivateServo.
				pin.
				val}
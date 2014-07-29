commands
servo: pin pwm: val
	self send:	{self class rqServoPWM.
				pin.
				val bitAnd: 16rFF.
				(val >> 8) bitAnd: 16rFF}
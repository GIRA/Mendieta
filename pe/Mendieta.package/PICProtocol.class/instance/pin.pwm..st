commands
pin: pin pwm: val
	self send:	{self class rqPinPWM.
				pin.
				val bitAnd: 16rFF.
				(val >> 8) bitAnd: 16rFF}
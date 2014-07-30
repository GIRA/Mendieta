servos
servoOnPin: pinNumber angle: degrees
	| val |
	val := (degrees / 180 * 2000 + 500) rounded.
	self send:	{self class rqServoPWM.
				pinNumber.
				val bitAnd: 16rFF.
				(val >> 8) bitAnd: 16rFF}
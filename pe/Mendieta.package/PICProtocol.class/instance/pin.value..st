commands
pin: pin value: val
	self send:	{self class rqPinValue.
				pin.
				val}
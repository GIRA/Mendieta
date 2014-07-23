commands
digitalWrite: pin value: val
	self send:	{self class rqDigitalWrite.
				pin.
				val}
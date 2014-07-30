digital pins
digitalWrite: pinNumber value: value
	pins at: pinNumber put: value.
	self send:	{self class rqDigitalWrite.
				pinNumber.
				value}
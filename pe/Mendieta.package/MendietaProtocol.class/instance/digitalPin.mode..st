digital pins
digitalPin: pinNumber mode: mode
	pinModes at: pinNumber put: mode.
	self send:	{self class rqPinMode.
			pinNumber.
			mode}
	
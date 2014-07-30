initialize-release
initialize
	digitalPins := Dictionary new.
	analogPins := Dictionary new.
	(1 to: 40) collect: [:pinNumber || class |
		true caseOf: {
			[self isAnalog: pinNumber] 
				-> [analogPins 
						at: pinNumber 
						put: (ArduinoAnalogPin on: self number: pinNumber)].
			[self isDigital: pinNumber] 
				-> [digitalPins
						at: pinNumber
						put: (ArduinoDigitalPin on: self number: pinNumber)]
		} otherwise: ["Do nothing"]]
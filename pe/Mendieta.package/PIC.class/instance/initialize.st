initializing
initialize
	pins := (1 to: 40) collect: [:pinNumber || class |
		class := true caseOf: {
			[self isAnalog: pinNumber] -> [PICAnalogPin].
			[self isDigital: pinNumber] -> [PICDigitalPin]
		} otherwise: [PICInvalidPin].
		class on: self number: pinNumber].
	protocol := PICProtocol new.
	super initialize
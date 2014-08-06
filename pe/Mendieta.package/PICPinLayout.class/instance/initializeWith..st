initialize
initializeWith: aPIC
	pins := (1 to: 40) collect: [:pinNumber || class |
		class := true caseOf: {
			[self isAnalog: pinNumber] -> [PICAnalogPin].
			[self isDigital: pinNumber] -> [PICDigitalPin]
		} otherwise: [PICInvalidPin].
		class on: aPIC number: pinNumber].
	self initialize
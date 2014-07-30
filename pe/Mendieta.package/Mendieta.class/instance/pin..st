accessing
pin: pinNumber
	(self isAnalog: pinNumber) ifTrue: [^ self analogPin: pinNumber].
	(self isDigital: pinNumber) ifTrue: [^ self digitalPin: pinNumber].
	^ self inaccessiblePinError
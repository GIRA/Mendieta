accessing
analogPin: pinNumber value: aNumber
	self flag: #Richo. "HACK!"
	(#(33 34) includes: pinNumber)
		ifTrue: [| val |
			val := aNumber min: 1023 max: 0.
			pic protocol
				continuousServo: pinNumber
				speed: ((510 / 1023) * val - 255) rounded.
			^ self].
	^ (pic pin: pinNumber) value: aNumber
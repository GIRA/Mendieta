accessing
digitalPin: pin value: aBoolean
	^ (pic pin: pin) value: (aBoolean ifTrue: [1] ifFalse: [0])
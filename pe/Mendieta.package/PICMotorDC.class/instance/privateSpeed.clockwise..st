private
privateSpeed: aNumber clockwise: aBoolean
	self pinsWithIndexDo: [:pin :index || p |
		p := index \\ 3.
		p = 1 
			ifTrue: [pic protocol
				pin: pin number
				pwm: aNumber]
			ifFalse: [pic protocol
				pin: pin number
				value: (p = 2
					ifTrue: [aBoolean ifTrue: [1] ifFalse: [0]]
					ifFalse: [aBoolean ifTrue: [0] ifFalse: [1]])]]

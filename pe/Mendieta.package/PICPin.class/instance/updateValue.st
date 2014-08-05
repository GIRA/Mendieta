updating
updateValue
	self flag: #Richo. "HACK to allow servo pwm"
	(#(33 34) includes: number)
		ifTrue: ["Servo pins"
			pic protocol
				continuousServo: number
				speed: ((510 / 1023) * value - 255) rounded.
			^ self].
	pic protocol
		digitalWrite: number
		value: (value > 0
			ifTrue: [1] ifFalse: [0])
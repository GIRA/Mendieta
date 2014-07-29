updating
updateValue
	self flag: #Richo. "HACK to allow servo pwm"
	(#(33 34) includes: number)
		ifTrue: ["Servo pins"
			pic protocol
				servo: number
				pwm: (value / 1023 * 2000 + 500) rounded.
			^ self].
	pic protocol
		digitalWrite: number
		value: (value > 0
			ifTrue: [1] ifFalse: [0])
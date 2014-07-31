updating
updateValue: old
	self flag: #Richo. "HACK to allow servo pwm"
	(#(33 34) includes: number)
		ifTrue: ["Servo pins"
					fork ifTrue: [^ self].
			(value - old) abs > 500
				ifTrue: [
					[fork := true.
					pic protocol
					servo: number
					active: 0.					
					300 milliSeconds asDelay wait.
					pic protocol
						servo: number active: 1.
					pic protocol
						servo: number
						pwm: (value / 1023 * 2000 + 500) rounded.
					fork := false] fork.
					^ self].
			pic protocol
				servo: number
				pwm: (value / 1023 * 2000 + 500) rounded.
			^ self].
	pic protocol
		digitalWrite: number
		value: (value > 0
			ifTrue: [1] ifFalse: [0])
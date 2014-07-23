updating
updateValue
	pic protocol
		digitalWrite: number
		value: (value > 0
			ifTrue: [1] ifFalse: [0])
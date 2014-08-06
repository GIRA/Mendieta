updating pin
updateValue: value on: number using: board
	board protocol
		pin: number
		value: (value > 0
			ifTrue: [1] ifFalse: [0])
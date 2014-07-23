processing input
processAnalogs: input
#(2 3 4 5 7 8 9 10 35 36 34 37 33) 
	withIndexDo: [:pinNumber :index || pin |
		pin := self pin: pinNumber.
		pin mode isInput
			ifTrue: [| i1 i2 |
				i1 := index * 2 + 2.
				i2 := i1 + 1.
				pin value: ((input at: i1)	
						bitOr: ((input at: i2)
						bitShift: 8))]].
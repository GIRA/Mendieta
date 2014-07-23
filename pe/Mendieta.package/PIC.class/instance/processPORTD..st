processing input
processPORTD: input
	#(19 20 21 22 27 28 29 30) withIndexDo: [:pinNumber :index || pin |
		pin := self pin: pinNumber.
		pin mode isInput
			ifTrue: [| port val |
				port := input at: 2.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pin value: val]].
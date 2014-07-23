processing input
processPORTA: input
	(2 to: 7) withIndexDo: [:pinNumber :index || pin |
		pin := self pin: pinNumber.
		pin mode isInput
			ifTrue: [| port val |
				port := input at: 1.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pin value: val]].
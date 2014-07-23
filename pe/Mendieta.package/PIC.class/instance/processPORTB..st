processing input
processPORTB: input
	(33 to: 40) withIndexDo: [:pinNumber :index || pin |
		pin := self pin: pinNumber.
		pin mode isInput
			ifTrue: [| port val |
				port := input at: 3.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pin value: val]]
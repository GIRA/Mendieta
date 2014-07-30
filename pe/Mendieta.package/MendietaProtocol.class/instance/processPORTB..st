processing input
processPORTB: input
	(33 to: 40) withIndexDo: [:pinNumber :index || mode |
		mode := pinModes at: pinNumber.
		mode = 1
			ifTrue: [| port val |
				port := input at: 3.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pins at: pinNumber put: val]]
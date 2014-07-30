processing input
processPORTA: input
	(2 to: 7) withIndexDo: [:pinNumber :index || mode |
		mode := pinModes at: pinNumber.
		mode = 1
			ifTrue: [| port val |
				port := input at: 1.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pins at: pinNumber put: val]].
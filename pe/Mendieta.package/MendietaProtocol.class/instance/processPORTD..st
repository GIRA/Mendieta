processing input
processPORTD: input
	#(19 20 21 22 27 28 29 30) withIndexDo: [:pinNumber :index || mode |
		mode := pinModes at: pinNumber.
		mode = 1
			ifTrue: [| port val |
				port := input at: 2.
				val := (port bitShift: (index - 1) * -1) bitAnd: 1.
				pins at: pinNumber put: val]].
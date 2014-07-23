slots - ports
setRB2: aNumber
	(self costumeRespondingTo: #analogPin:value:)
		ifNotNil: [:aCostume |
			aCostume analogPin: 35 value: aNumber]
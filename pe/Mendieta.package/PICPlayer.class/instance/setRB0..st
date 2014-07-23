slots - ports
setRB0: aNumber
	(self costumeRespondingTo: #analogPin:value:)
		ifNotNil: [:aCostume |
			aCostume analogPin: 33 value: aNumber]
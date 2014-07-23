slots - ports
setRB3: aNumber
	(self costumeRespondingTo: #analogPin:value:)
		ifNotNil: [:aCostume |
			aCostume analogPin: 36 value: aNumber]
slots - ports
setRB4: aNumber
	(self costumeRespondingTo: #analogPin:value:)
		ifNotNil: [:aCostume |
			aCostume analogPin: 37 value: aNumber]
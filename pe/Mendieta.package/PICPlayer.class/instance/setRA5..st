slots - ports
setRA5: aNumber
	(self costumeRespondingTo: #analogPin:value:)
		ifNotNil: [:aCostume |
			aCostume analogPin: 7 value: aNumber]
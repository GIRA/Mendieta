slots - ports
setRB7: aBoolean
	(self costumeRespondingTo: #digitalPin:value:)
		ifNotNil: [:aCostume |
			aCostume digitalPin: 40 value: aBoolean]
slots - ports
setRB5: aBoolean
	(self costumeRespondingTo: #digitalPin:value:)
		ifNotNil: [:aCostume |
			aCostume digitalPin: 38 value: aBoolean]
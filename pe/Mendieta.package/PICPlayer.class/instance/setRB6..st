slots - ports
setRB6: aBoolean
	(self costumeRespondingTo: #digitalPin:value:)
		ifNotNil: [:aCostume |
			aCostume digitalPin: 39 value: aBoolean]
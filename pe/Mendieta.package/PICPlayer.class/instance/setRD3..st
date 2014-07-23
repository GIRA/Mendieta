slots - ports
setRD3: aBoolean
	(self costumeRespondingTo: #digitalPin:value:)
		ifNotNil: [:aCostume |
			aCostume digitalPin: 22 value: aBoolean]
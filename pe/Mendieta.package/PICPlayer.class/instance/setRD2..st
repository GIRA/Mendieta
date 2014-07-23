slots - ports
setRD2: aBoolean
	(self costumeRespondingTo: #digitalPin:value:)
		ifNotNil: [:aCostume |
			aCostume digitalPin: 21 value: aBoolean]
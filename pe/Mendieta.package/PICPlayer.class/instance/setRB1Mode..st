slots - ports mode
setRB1Mode: aSymbol
	(self costumeRespondingTo: #pin:mode:)
		ifNotNil: [:aCostume |
			aCostume pin: 34 mode: aSymbol]
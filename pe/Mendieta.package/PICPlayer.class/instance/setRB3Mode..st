slots - ports mode
setRB3Mode: aSymbol
	(self costumeRespondingTo: #pin:mode:)
		ifNotNil: [:aCostume |
			aCostume pin: 36 mode: aSymbol]
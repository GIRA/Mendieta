slots - ports mode
setRA5Mode: aSymbol
	(self costumeRespondingTo: #pin:mode:)
		ifNotNil: [:aCostume |
			aCostume pin: 7 mode: aSymbol]
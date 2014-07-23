slots - ports mode
setRD0Mode: aSymbol
	(self costumeRespondingTo: #pin:mode:)
		ifNotNil: [:aCostume |
			aCostume pin: 19 mode: aSymbol]
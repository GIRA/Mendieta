slots - ports mode
setRA2Mode: aSymbol
	(self costumeRespondingTo: #pin:mode:)
		ifNotNil: [:aCostume |
			aCostume pin: 4 mode: aSymbol]
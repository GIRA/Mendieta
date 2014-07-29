accessing
validPins
	^ pins reject: [:pin | pin isInvalid]
accessing
pin: pin mode: mode
	^ (pic pin: pin) mode: (mode = #input
			ifTrue: [PICInputMode new]
			ifFalse: [PICOutputMode new])
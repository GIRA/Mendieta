accessing
pin: pin mode: mode
	^ (pic pin: pin) mode: (mode = #input ifTrue: [PICInput new] ifFalse: [PICOutput new])
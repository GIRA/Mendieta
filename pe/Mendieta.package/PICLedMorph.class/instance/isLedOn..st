turning on/off
isLedOn: aBoolean
	aBoolean
		ifTrue: [device on]
		ifFalse: [device off]
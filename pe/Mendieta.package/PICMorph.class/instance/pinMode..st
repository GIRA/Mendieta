accessing
pinMode: pin
	^ (pic pin: pin) mode isInput ifTrue: [#input] ifFalse: [#output]
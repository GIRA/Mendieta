accessing
value: aNumber
	value := aNumber.
	mode isOutput ifTrue: [self updateValue]
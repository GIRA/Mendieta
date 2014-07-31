accessing
value: aNumber
	| old |
	old := value.
	value := aNumber.
	mode isOutput ifTrue: [self updateValue: old]
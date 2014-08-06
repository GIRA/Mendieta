attaching
attachToPins: anArrayOfPins
	self isAttached ifTrue: [^ self].
	anArrayOfPins ifEmpty: [^ self].
	pins := anArrayOfPins.
	pic := pins first board.
	pic privateAttach: self.
	self configure
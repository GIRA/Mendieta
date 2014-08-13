pins
pinsAverage
	| c t |
	c := 0.0.
	t := pins size.
	t = 0 ifTrue: [^ c].
	1 to: t do: [:i | c := c + (pins at: i) value].
	^ c / t
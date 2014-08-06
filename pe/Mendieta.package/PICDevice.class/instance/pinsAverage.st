pins
pinsAverage
	| c |
	c := 0.0.
	1 to: pins size do: [:i | c := c + (pins at: i) value].
	^ c / pins size
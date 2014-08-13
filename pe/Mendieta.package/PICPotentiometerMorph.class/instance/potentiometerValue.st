accessing
potentiometerValue
	^ [device value] on: Error do: [-1]
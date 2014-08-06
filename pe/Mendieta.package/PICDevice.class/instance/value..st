accessing
value: aNumber
	"Set all pins to have this value"
	^ pins do: [:pin | pin value: aNumber]
as yet unclassified
degrees: aNumber
	degrees := aNumber min: 180 max: 0.
	self pinsDo: [:pin |
		pic protocol
			servo: pin number
			pwm: (degrees / 180 * 2000 + 500) rounded]
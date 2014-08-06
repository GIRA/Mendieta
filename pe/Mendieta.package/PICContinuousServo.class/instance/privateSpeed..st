private
privateSpeed: aNumber
	self pinsDo: [:pin |
		pic protocol
			continuousServo: pin number
			speed: aNumber]

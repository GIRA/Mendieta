accessing
speed: aNumber
	speed := aNumber min: 100 max: -100.
	self privateSpeed: (speed abs / 100 * 3000) rounded
		clockwise: speed > 0
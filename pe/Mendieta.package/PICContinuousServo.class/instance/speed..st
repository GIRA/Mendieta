accessing
speed: aNumber
	speed := aNumber min: 100 max: -100.
	self privateSpeed: (speed / 100 * 255) rounded
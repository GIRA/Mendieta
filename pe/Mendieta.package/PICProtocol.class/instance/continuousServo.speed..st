commands
continuousServo: pin speed: val
	| direction speed |
	direction := val sign + 1.
	speed := val abs.
	self send:	{self class rqContinuousServo.
				pin.
				direction.
				speed}
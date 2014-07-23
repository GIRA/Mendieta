accessing
pin: pinNumber
	self assert: (pinNumber between: 1 and: 40) 
		description: 'pinNumber must be between 1 and 40'.
	^ pins at: pinNumber
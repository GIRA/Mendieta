accessing
isPressed
	^ [device isPressed]
		on: Error
		do: [false]
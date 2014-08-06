attaching
attachToPins: pinNumbers on: aBoard
	^ self attachToPins: (pinNumbers collect: [:n | aBoard pin: n])
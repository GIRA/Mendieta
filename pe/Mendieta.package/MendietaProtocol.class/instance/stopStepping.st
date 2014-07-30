stepping
stopStepping
	process ifNil: [^ self].
	process terminate.
	process := nil
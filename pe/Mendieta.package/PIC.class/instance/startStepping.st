stepping
startStepping
	process ifNotNil: [^ self].
	process := [[
		self stepTime milliSeconds asDelay wait.
		self step.
		] repeat]
			forkNamed: self asString
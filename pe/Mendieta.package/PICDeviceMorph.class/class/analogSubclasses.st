devices
analogSubclasses
	^ (self allSubclasses select: [:each | each isAnalog]) asArray
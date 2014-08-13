devices
digitalSubclasses
	^ (self allSubclasses select: [:each | each isDigital]) asArray
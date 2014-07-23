class initialization
shutDown
	self allInstancesDo: [:each | each disconnect]
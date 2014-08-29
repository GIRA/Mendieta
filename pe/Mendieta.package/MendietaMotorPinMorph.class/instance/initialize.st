initialize-release
initialize
	super initialize.
	self extent: self class form extent.
	attachmentPoint center: self center
	
initialization
initialize
	super initialize.
	device := self class device new.
	self extent: self class form extent;
		initializeAttachmentPoints.
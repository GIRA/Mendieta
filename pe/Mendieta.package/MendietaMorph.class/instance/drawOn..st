drawing
drawOn: aCanvas
	super drawOn: aCanvas."
	form ifNotNil: [:f |
		aCanvas translucentImage: f at: self fullBounds topLeft - 1]"
initialize-release
initialize
	super initialize.
	self extent: 42@32;
		fillStyle: ((GradientFillStyle 
			ramp: {0.0->(Color r: 1.0 g: 1.0 b: 0.968).
				 1.0->(Color r: 1.0 g: 0.903 b: 0.581)})
			origin: 0@0;
			direction: 0@27;
			normal: 38@0;
			radial: false;
			yourself);
		borderWidth: 0;
		borderColor: Color red;
		initializeEventHandling;
		initializeAttachmentPoint
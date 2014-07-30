initialize-release
initialize
	super initialize.
	pic := PIC new.
	self extent: 338@270;
		cornerStyle: #rounded;
		fillStyle: ((GradientFillStyle
			ramp:  { 0.0->(Color r: 1.0 g: 0.871 b: 0.452).
				1.0->(Color r: 0.516 g: 0.355 b: 0.0)})
			origin: 0 @ 0;
			direction: 332 @ 358;
			normal: -358 @ 332;
			radial: false);
		buildSubmorphs
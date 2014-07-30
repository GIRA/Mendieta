building
buildDigitalPins
	#(27 28 29 33 34) withIndexDo: [:pinNumber :i || pin label |
		pin := (MendietaDigitalPinMorph on: (pic pin: pinNumber))
			position: (99@221) + (i - 1* 45.0@0.0);
			yourself.
		label := TextMorph new
			contentsWrapped: 'D', i asString;
			fontName: 'Accumon' size: 9;
			extent: 44@26.0;
			textColor: (Color r: 0.387 g: 0.387 b: 0.387);
			centered;
			position: (99@204.0) + (i - 1 * 45.0@0.0);
			yourself.
		self addMorph: label;
			addMorph: pin]
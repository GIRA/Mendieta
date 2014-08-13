building
buildAnalogPins
	#(8 7 5 4) withIndexDo: [:pinNumber :i || pin label |
		pin := (MendietaAnalogPinMorph on: (pic pin: pinNumber))
			position: (136@16) + (i - 1 * 45.0@0.0);
			yourself.
		label := TextMorph new
			contentsWrapped: 'A', i asString;
			fontName: 'Accumon' size: 9;
			extent: 44@26.0;
			textColor: (Color r: 0.387 g: 0.387 b: 0.387);
			centered;
			position: (135@49.0) + (i - 1 * 45.0@0.0);
			yourself.
		self addMorph: label;
			addMorph: pin]
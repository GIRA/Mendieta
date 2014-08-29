building
buildMotorPins
	#(33 34) withIndexDo: [:pinNumber :i || pin label |
		pin := (MendietaMotorPinMorph on: (pic pin: pinNumber))
			position: (314 @ 122) + (0.0 @ (i - 1* 40.0));
			yourself.
		"label := TextMorph new
			contentsWrapped: 'M', i asString;
			fontName: 'Accumon' size: 9;
			extent: 44@26.0;
			textColor: (Color r: 0.387 g: 0.387 b: 0.387);
			centered;
			position: (314 @ 122) + (0.0 @ (i - 1* 40.0));
			yourself."
		self" addMorph: label;"
			addMorph: pin]
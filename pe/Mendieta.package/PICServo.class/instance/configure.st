as yet unclassified
configure
	self setPinsOutput;
		pinsDo: [:pin |
			pic protocol
				servo: pin number
				active: 1];
		degrees: self degrees
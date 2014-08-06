as yet unclassified
deleteConfiguration
	self pinsDo: [:pin |
			pic protocol
				servo: pin number
				active: 0].
	super deleteConfiguration

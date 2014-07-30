attaching
attach: aDevice 
	| wire |
	self halt.
	wire := aDevice class newConnectorFromMorph: attachmentPoint toMorph: aDevice attachmentPoint.
	aDevice attach: pin by: wire.
	self move: aDevice
initializing
initialize
	super initialize.
	protocol := PICProtocol new.
	devices := OrderedCollection new.
	layout := PICPinLayout on: self.
	super initialize
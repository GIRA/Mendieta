private
receive
	| bufSize buf |
	self isConnected ifFalse: [^#[]].
	bufSize := 65.	
	buf := ByteArray new: bufSize.
	^ self hid read: device into: buf
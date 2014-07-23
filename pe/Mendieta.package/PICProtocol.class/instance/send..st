private
send: aByteArray
	| buf |
	self isConnected ifFalse: [^ self].
	aByteArray size > 64 ifTrue: [^ self].
	"IMPORTANT:
	The buffer *must* be 65 bytes long 
	and the first element *must* be 0"
	buf := ByteArray new: 65 withAll: 0.
	buf replaceFrom: 2
		to: aByteArray size + 1
		with: aByteArray.
	self hid write: device with: buf.
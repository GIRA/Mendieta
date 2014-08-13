servo
setDegrees: aNumber
	^ self sendMessageToCostume: #degrees: with: aNumber
continuous servo
setSpeed: aNumber
	^ self sendMessageToCostume: #speed: with:aNumber
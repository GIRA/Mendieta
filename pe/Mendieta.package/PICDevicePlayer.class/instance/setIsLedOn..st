led
setIsLedOn: aBoolean
	^ self sendMessageToCostume: #isLedOn: with: aBoolean
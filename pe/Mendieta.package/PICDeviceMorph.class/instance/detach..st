attaching
detach: aPICWireMorph 
	| index |
	index := attachmentPoints
				indexOf: aPICWireMorph sourceMorph 
				ifAbsent: [attachmentPoints 	
								indexOf: aPICWireMorph destinationMorph 
								ifAbsent: [^ self]].
	(self isAttachedAt: index) ifTrue: [
		attachments at: index put: nil.
		self refreshDeviceAttachments] 
attaching
detach
	self isAttached ifFalse: [^ self].
	self deleteConfiguration.
	pic privateDetach: self.
	pic := nil.
	pins := #()
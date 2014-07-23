instance creation
new
	^ uniqueInstance ifNil: [uniqueInstance := self basicNew]
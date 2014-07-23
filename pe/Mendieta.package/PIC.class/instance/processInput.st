processing input
processInput
	| input |
	input := protocol receive.
	input isEmpty ifTrue: [^ self].
"	Transcript show: (input fourth bitOr: (input fifth bitShift: 8)); cr."
	Transcript show: input printString; cr.

	self processPORTA: input;
		processPORTD: input;
		processPORTB: input;
		processAnalogs: input
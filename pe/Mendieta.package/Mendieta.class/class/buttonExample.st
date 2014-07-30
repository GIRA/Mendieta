examples
buttonExample
	"
	This example requires a button attached to the digital pin 7.
	It creates a TextMorph that shows if the button is pressed..
	
	self buttonExample.
	"
	
	| arduino button textMorph process buttonMorph |
	"Just to be sure, disconnect all other instances"
	Mendieta instancesConnected do: [:each | each disconnect].
	
	"Create and connect your arduino. Install the firware automatically if not installed already"
	arduino := Mendieta new.
	arduino connect.

	"Create a button and attach it to pin 7"
	button := EButton new.
	button attach: (arduino digitalPin: 7).
	
	"Create an arrow to show potentiometer value"
	textMorph := TextMorph new contents: 'Not pressed'.
	
	"Create and start a process to update the arrow's rotation"
	process := [[textMorph contents: (button value = 1 ifTrue: ['Pressed'] ifFalse: ['Not pressed']).
				textMorph center: World center.
				10 milliSeconds asDelay wait] repeat]
					forkNamed: 'buttonExample process'.
	
	"Create clean up button"
	buttonMorph := SimpleButtonMorph newWithLabel: 'Clean up'.
	buttonMorph
		actionSelector: #value;
		target: [process terminate.
			arduino disconnect.
			textMorph delete.
			buttonMorph delete].

	"Open morphs in World"
	textMorph openInWorld.
	buttonMorph openInWorld.
	textMorph center: World center.
	buttonMorph center: World center.
	buttonMorph top: textMorph bottom + 10.
	
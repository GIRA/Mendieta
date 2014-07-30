initialize-release
reconfigurePins
	"Overriden to avoid DuinoBot issue on Linux"
	digitalPins values , analogPins values", motorPins values"
		do: [:each | 
			10 milliSeconds asDelay wait.
			each refresh]
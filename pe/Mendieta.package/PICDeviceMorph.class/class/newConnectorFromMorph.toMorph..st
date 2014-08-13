connectors
newConnectorFromMorph: m1 toMorph: m2
	^ (PICWireMorph fromMorph: m1 toMorph: m2) 
			lineColor: Color gray;
			yourself
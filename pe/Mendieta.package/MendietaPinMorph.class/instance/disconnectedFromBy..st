connectors
disconnectedFromBy: aConnector
	[aConnector destinationMorph
		ifNotNil: [:m | m owner detach: aConnector]]
			on: Error do: ["Do nothing"].
	[aConnector sourceMorph 
		ifNotNil: [:m | m owner detach: aConnector]]
			on: Error do: ["Do nothing"].

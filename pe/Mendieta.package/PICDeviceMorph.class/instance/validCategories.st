viewer category filter
validCategories
	"Returns valid categories for this object"
	^ (self class additionsToViewerCategories collect: [:each| each first])
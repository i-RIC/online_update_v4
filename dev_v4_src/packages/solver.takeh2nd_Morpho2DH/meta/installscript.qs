function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/solvers/takeh2nd_Morpho2DH");
}

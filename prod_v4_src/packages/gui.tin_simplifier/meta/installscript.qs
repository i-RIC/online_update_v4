function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/guis/tin_simplifier");
}

Component.prototype.createOperations = function()
{
	component.createOperations();
}

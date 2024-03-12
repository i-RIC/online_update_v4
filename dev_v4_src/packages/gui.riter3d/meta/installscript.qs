function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/guis/riter3d");
}

Component.prototype.createOperations = function()
{
	component.createOperations();
}

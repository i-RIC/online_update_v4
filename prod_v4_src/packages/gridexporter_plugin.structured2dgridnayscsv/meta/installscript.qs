function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/gridexporter_plugins/structured2dgridnayscsvexporter");
}

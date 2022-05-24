function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/gridimporter_plugins/structured2dgridnaysgridimporter");
}

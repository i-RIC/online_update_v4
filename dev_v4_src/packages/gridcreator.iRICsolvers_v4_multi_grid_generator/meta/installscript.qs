function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/gridcreators/iRICsolvers_v4_multi_grid_generator");
}

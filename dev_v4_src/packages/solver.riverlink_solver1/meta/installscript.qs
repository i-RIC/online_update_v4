function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/solvers/riverlink_solver1");
}

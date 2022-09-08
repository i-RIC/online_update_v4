function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/solvers/sk-lb_solver.river2d");
}

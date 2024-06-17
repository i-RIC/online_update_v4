function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
	// call default implementation to actually install files
	component.createOperations();

	component.addOperation("Execute", "@TargetDir@/miniconda_install.bat", "@TargetDir@", "@TargetDir@\\Miniconda3", "UNDOEXECUTE", "@TargetDir@/miniconda_uninstall.bat", "@TargetDir@\\Miniconda3");

	component.addOperation("Delete", "@TargetDir@/Miniconda3-py312_24.4.0-0-Windows-x86_64.exe");
}

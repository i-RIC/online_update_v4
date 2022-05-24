function Component()
{}

Component.prototype.createOperationsForArchive = function(archive)
{
	component.addOperation("Extract", archive, "@TargetDir@/guis/prepost");
}

Component.prototype.createOperations = function()
{
	component.createOperations();

	component.addOperation("CreateShortcut", "@TargetDir@/guis/prepost/iRIC.exe",
		"@StartMenuDir@/iRIC v4 (beta).lnk", "workingDirectory=@TargetDir@/guis/prepost");
	component.addOperation("CreateShortcut", "@TargetDir@/guis/prepost/iRIC.exe",
		"@DesktopDir@/iRIC v4 (beta).lnk", "workingDirectory=@TargetDir@/guis/prepost");
	component.addOperation("CreateShortcut", "@TargetDir@/maintenancetool.exe",
		"@StartMenuDir@/iRIC Maintainance.lnk", "--updater", "workingDirectory=@TargetDir@");
	component.addOperation("CreateShortcut", "@TargetDir@/maintenancetool.exe",
		"@StartMenuDir@/Uninstall iRIC.lnk", "workingDirectory=@TargetDir@");
}

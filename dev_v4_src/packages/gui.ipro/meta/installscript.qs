function Component()
{}

Component.prototype.createOperations = function()
{
	component.createOperations();
    component.addOperation("RegisterFileType", "ipro", "@TargetDir@\\guis\\prepost\\iRIC.exe" + " \"%1\"",
        "iRIC Project file", "application/iric",
        "@TargetDir@/guis/prepost/iconiRICFile.ico", "ProgId=iRICProject.ipro");
}

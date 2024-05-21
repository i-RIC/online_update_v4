function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
	// call default implementation to actually install files
	component.createOperations();

	component.addOperation("SimpleMoveFile", "@TargetDir@/iric.py", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/iric.py");
	component.addOperation("SimpleMoveFile", "@TargetDir@/_iric.pyd", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/_iric.pyd");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iricmi.py", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/iricmi.py");
	component.addOperation("SimpleMoveFile", "@TargetDir@/_iricmi.pyd", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/_iricmi.pyd");
	component.addOperation("SimpleMoveFile", "@TargetDir@/hdf5.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/hdf5.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iricmi.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/iricmi.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iriclib.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/iriclib.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/szip.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/szip.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/zlib.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/zlib.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/PocoFoundation.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/PocoFoundation.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/PocoXML.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/PocoXML.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonCore-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonCore-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonDataModel-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonDataModel-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonMath-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonMath-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonMisc-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonMisc-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonSystem-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonSystem-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtkCommonTransforms-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtkCommonTransforms-8.2.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/vtksys-8.2.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/vtksys-8.2.dll");

	component.addOperation("SimpleMoveFile", "@TargetDir@/iricmi_run.py", "@TargetDir@/Miniconda3/envs/iric/Library/bin/iricmi_run.py");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iricmi_run.bat", "@TargetDir@/Miniconda3/envs/iric/Library/bin/iricmi_run.bat");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iricmi_server.exe", "@TargetDir@/Miniconda3/envs/iric/Library/bin/iricmi_server.exe");

	component.addOperation("SimpleMoveFile", "@TargetDir@/libifcoremd.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/libifcoremd.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/libifcorert.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/libifcorert.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/libifportmd.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/libifportmd.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/libiomp5md.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/libiomp5md.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/libmmd.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/libmmd.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/svml_dispmd.dll", "@TargetDir@/Miniconda3/envs/iric/Library/bin/svml_dispmd.dll");

	component.addOperation("EnvironmentVariable", "IRICMI_ROOT_PATH", "@TargetDir@", true);
	component.addOperation("EnvironmentVariable", "IRICMI_LOG_LEVEL", "WARNING", true);
	component.addOperation("EnvironmentVariable", "IRIC_LOG_LEVEL", "ERROR", true);
}

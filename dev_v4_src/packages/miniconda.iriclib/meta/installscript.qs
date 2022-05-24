function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
	// call default implementation to actually install files
	component.createOperations();

	component.addOperation("SimpleMoveFile", "@TargetDir@/_iric.pyd", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/_iric.pyd");
	component.addOperation("SimpleMoveFile", "@TargetDir@/_iricd.pyd", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/_iricd.pyd");
	component.addOperation("SimpleMoveFile", "@TargetDir@/hdf5.dll", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/hdf5.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iric.py", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/iric.py");
	component.addOperation("SimpleMoveFile", "@TargetDir@/iriclib.dll", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/iriclib.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/szip.dll", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/szip.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/zlib.dll", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/zlib.dll");
	component.addOperation("SimpleMoveFile", "@TargetDir@/PocoFoundation.dll", "@TargetDir@/Miniconda3/envs/iric/Lib/site-packages/PocoFoundation.dll");
}

function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
	// call default implementation to actually install files
	component.createOperations();

	if (systemInfo.productType === "windows") {
		install_miniconda();
	}
	delete_installer();
}

function install_miniconda()
{
	component.addOperation("Execute", "@TargetDir@/Miniconda3-py38_4.9.2-Windows-x86_64.exe", "/InstallationType=JustMe", "/RegisterPython=0", "/AddToPath=0", "/S", "/D=@TargetDir@\\Miniconda3");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "create", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "python", "-y", "-q");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/intel-openmp-2020.3-h57928b3_311.tar.bz2");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/libblas-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/libcblas-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/liblapack-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/mkl-2020.4-hb70f87d_311.tar.bz2");
	component.addOperation("Execute", "@TargetDir@/Miniconda3/condabin/conda.bat", "install", "-p", "@TargetDir@/Miniconda3/envs/iric", "--offline", "@TargetDir@/numpy-1.19.4-py38h0cc643e_1.tar.bz2");
}

function delete_installer()
{
	component.addOperation("Delete", "@TargetDir@/Miniconda3-py38_4.9.2-Windows-x86_64.exe");
	component.addOperation("Delete", "@TargetDir@/intel-openmp-2020.3-h57928b3_311.tar.bz2");
	component.addOperation("Delete", "@TargetDir@/libblas-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Delete", "@TargetDir@/libcblas-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Delete", "@TargetDir@/liblapack-3.8.0-21_mkl.tar.bz2");
	component.addOperation("Delete", "@TargetDir@/mkl-2020.4-hb70f87d_311.tar.bz2");
	component.addOperation("Delete", "@TargetDir@/numpy-1.19.4-py38h0cc643e_1.tar.bz2");
}

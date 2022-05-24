function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
	// call default implementation to actually install files
	component.createOperations();

	if (systemInfo.productType === "windows") {
		install_runtime("14.0", 30133);
	}
	delete_runtime();
}

function install_runtime(major, build)
{
	var executable = "@TargetDir@\\VC_redist.x64.exe";
	var runtime = "Microsoft Visual C++ 2015-2019 Runtime Bld " + build.toString();
	var key = "HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\VisualStudio\\" + major + "\\VC\\Runtimes\\X64"

	// check if major version is installed
	var installed = installer.execute("reg", new Array("QUERY", key, "/v", "Installed"))[0];
	if (installed) {
		// check build number
		var output = installer.execute("reg", new Array("QUERY", key, "/v", "Bld"))[0];
		var tokens = output.split(" ");
		var bld = parseInt(tokens[tokens.length-1])
		console.log("Found Microsoft Visual C++ 2015-2019 Runtime Bld " + bld.toString());
		if (bld < build) {
			console.log("Installing " + runtime + ": " + executable + " /quiet /norestart");
			component.addOperation("Execute", executable, "/quiet", "/norestart");
		} else {
			console.log("No need to install " + runtime);
		}
	} else {
		console.log("Installing " + runtime + ": " + executable + " /quiet");
		component.addOperation("Execute", executable, "/quiet");
	}
}

function delete_runtime()
{
	var executable = "@TargetDir@\\VC_redist.x64.exe";
	component.addOperation("Delete", executable);
}

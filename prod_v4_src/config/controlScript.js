function Controller()
{
}

function onkeydownCallback()
{
	window.alert("onkeydown " + this.text);
}

function oninputCallback()
{
	window.alert("oninput " + this.text);
}

Controller.prototype.TargetDirectoryPageCallback = function()
{
	var widget = gui.currentPageWidget();
	widget.MessageLabel.setText("Please select the target directory to install iRIC.\nTarget directory should not contain spaces or non-ASCII characters.");
}

Controller.prototype.ReadyForInstallationPageCallback = function()
{
	var widget = gui.currentPageWidget();
	var targetDirPage = gui.pageWidgetByObjectName("TargetDirectoryPage");
	var targetDir = targetDirPage.TargetDirectoryLineEdit.text

	if (targetDir.indexOf(' ') >= 0) {
		widget.MessageLabel.setText("Install target folder path contains spaces. Please go back and fix.");
		widget.setComplete(false);
	} else {
		widget.MessageLabel.setText("Setup is now ready to begin installing " + widget.productName() + " on your computer.");
		widget.setComplete(true);
	}
}

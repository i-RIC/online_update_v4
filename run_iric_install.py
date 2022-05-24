# run_iric_install.py

import pyautogui, sys, time
import subprocess
import os
import tkinter as tk

def capture_and_push_artifact(path):
    pyautogui.screenshot(path)
    if os.environ.get('APPVEYOR') is not None:
        subprocess.call("appveyor PushArtifact " + path)
    return

# left = location[0]; top = location[1]; width = location[2]; height = location[3]
LEFT = 0
TOP = 1
WIDTH = 2
HEIGHT = 3

pyautogui.FAILSAFE = False

# place mouse on screen to start iRIC (if multiple screens)
pyautogui.moveTo(1, 1)

# verify resolution
screenWidth, screenHeight = pyautogui.size()
print("Screen resolution: {}x{}".format(screenWidth, screenHeight))

# minimize everything
pyautogui.hotkey('win', 'm')
time.sleep(3.0)
capture_and_push_artifact("iRIC-Install-00.png") # desktop

# start iRIC install
subprocess.Popen("iRIC_Installer_" + os.environ['RELEASE'] + "_" + os.environ['SHA1'] + ".exe")
time.sleep(90.0)
capture_and_push_artifact("iRIC-Install-01.png") # Setup

# click next
nextButton = pyautogui.locateCenterOnScreen('iRIC_Installer-NextButton-2012.png')
if nextButton is None:
    print("Didn't locate iRIC_Installer-NextButton-2012.png")
    sys.exit(1)

pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-02.png") # InstallationFolder

# copy installer location
pyautogui.hotkey('ctrl', 'a')
time.sleep(0.5)
pyautogui.hotkey('ctrl', 'c')
r = tk.Tk()
# keep the window from showing
r.withdraw()
# text from clipboard
install_location = r.clipboard_get()
print("Installation Folder:", install_location)

# click next
pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-03.png") # SelectComponents

# click next
pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-04.png") # LicenseAgreement

# click agree
acceptRadio = pyautogui.locateCenterOnScreen('iRIC_Installer-AcceptRadio-2012.png')
if acceptRadio is None:
    print("Didn't locate iRIC_Installer-AcceptRadio-2012.png")
    sys.exit(2)
pyautogui.moveTo(acceptRadio)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(acceptRadio)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-05.png") # LicenseAgreementAccept

# click next
pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-06.png") # StartMenushortcuts

# click next
pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-07.png") # ReadytoInstall

# click Install
pyautogui.moveTo(nextButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(nextButton)
time.sleep(360.0)
capture_and_push_artifact("iRIC-Install-08.png") # Finished

# click Finish
finishButton = pyautogui.locateCenterOnScreen('iRIC_Installer-FinishButton-2012.png')
if finishButton is None:
    print("Didn't locate iRIC_Installer-FinishButton-2012.png")
    sys.exit(3)
pyautogui.moveTo(finishButton)  # this might not be necessary (needs further testing - at least for iric installers)
pyautogui.click(finishButton)
time.sleep(1.0)
capture_and_push_artifact("iRIC-Install-09.png") # Done

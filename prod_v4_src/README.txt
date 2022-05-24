# Tool scripts in this folder

The workflow to use the scripts in this folder is as follow:

- Update the files in folders in "packages" folder
- run copy_release_and_version.py to update package.xml files
- run build_update_repository.py to update files in dev folder

The detailed descriptions on each scripts are as follows:

## copy_release_and_version.py

When solvers or GUI are updated, developers will modify definition.xml to
change release dates and version number.

But, we need to update release dates and version numbers in meta\package.xml too.
Doing this by hand is annoying process, so this script automate that.

## build_update_repository.py

This will run repogen.exe. 
It is important that this scripts runs "svn status" to know which packages are updated,
so you need to run this script BEFORE you commit the changes to dev_src folder.

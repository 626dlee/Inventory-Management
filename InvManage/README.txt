GROUP: Leftovers
Project: Inventory Management

The project was created using a third party GUI library called Qt.
In order to run the program trying to run the executable on a linux machine may work
with a ./InvManage, but if that doesn't work then you would need to download the
libraries and recompile the program.
The program was developed on a linux system so this is a walkthrough on how to 
set it up on a linux system, we are unsure how it would work on a Windows system, but
might be the same.

This is done by going to the Qt download site found at:
https://www.qt.io/download
and selecting the Open Source option, this is what we used for the project.
A Qt account is required, but it is all free.
This will download the installer, and when that is run make sure to select
a Qt language BY DEFAULT NO LANGUAGE IS SELECTED, UNLESS YOU SELECT ONE IT WON'T INSTALL ONE, 
we used 5.11, and at the bottom of the list there is a development
tool called Qt Creator, this makes the compiling easier.
In the creator just select File > Open project and select the InvManage.pro file, this should
open the project, it can then be compiled with the green arrow in the bottom left corner.
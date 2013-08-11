Textpad Editor
==============

Simple and lightweight text editor 

#### Compilation Instructions ####

**Linux, Mac OSX and other UNIX variants that support Qt**

You will only need the Qt4 developer libraries in order to compile the program.
To compile this program, simply execute the following command in a terminal (without qoutes): "qmake textpad-editor.pro && make", you should be in the directory where you extracted the tarball (use the "cd" command).
This will create an executable named "textpad-editor", to run it, simply type "./textpad-editor".

**Microsoft Windows (XP, Vista, 7, 8)**

You will need to install Qt and Qt Creator (you can download them at http://www.qt-project.org/downloads).
To compile this program, open the textpad-editor.pro file with Qt Creator, configure the project and press CTLR + R to run it.

Have a great time hacking around the source code!

#### F.A.Q ###

**Is Textpad Editor aiming to be a clone of the comercial Textpad?**

No, Textpad Editor is aiming to be a simple and general purpose text editor, like Microsoft Notepad, but with more features (such as line count and syntax highlighting) and multiplatform (using the Qt Framework).

**I found a problem with Textpad, how can I report it?**

You can report bugs at [http://sf.net/p/textpad-editor/discussion/bugs](http://sf.net/p/textpad-editor/discussion/bugs) or by sending me an e-mail to [alex_sr97@outlook.com](mailto:alex_sr97@outlook.com).

**I have an idea/suggestion, how can I ask for it to be implemented in Textpad?**

You can post your suggestions and/or ideas at [http://sourceforge.net/p/textpad-editor/discussion/suggestionsideas/](http://sourceforge.net/p/textpad-editor/discussion/suggestionsideas/), or you can send me an e-mail to [alex_sr97@outlook.com](mailto:alex_sr97@outlook.com).

####Changelog###

**0.1**

	+ Initial Release.

**0.2**

	+ Added file support (open and save).
	+ Added "Insert Date and Time".
	+ Directory reorganization.
	+ Code improvements.

**0.3**

	+ Added "Word Count".
	+ Added search capabilities.
	+ SDI-like Interface.
	+ More code improvements.

**0.4**

	+ Temporarily removed "Minimal Mode" and "Normal Mode" support (because of the code redesign)
	+ Removed SDI-like interface.
	+ Added read/write settings support.
	+ Added calculation of the size of the document.
	+ Added "Replace All" function.
	+ Added "Welcome Screen" (like in Scratch).
	+ Changed coding style to the "CamelCase" style.
	+ Even more code improvements.

**0.5**

	+ Removed Designer form, (the UI is created in the mainwindow.cpp file) for more customization and less bloatware code (ui_mainwindow.h was around 700 lines long, which were replaced by 148 lines of code).
	+ Added "Set Read Only" feature.
	+ Complete font styles support (bold, italics, underline and strikeout are now supported).
	+ New Search Dialog.
	+ Redesigned statusbar layout.
	+ Simplified code (but longer because of the UI creation functions).
	+ The code (cpp files) are now divided into different categories (for easier reading), such as "settings.cpp" and "document.cpp"
	+ Removed the "Welcome Screen"
	+ Added 8 Color schemes
    
**0.6**

    + Added "Highlight current line"
    + Minor fixes
    + Fully functional search dialog
    + Redesigned color schemes engine
    
**0.7**

    + More integration for Mac OS X
    + Added Faenza icon set for Mac OS X
    + Added Syntax Highlighting 
    + Minor bug fixes
    + Smaller toolbar in Mac OS X (for centered icons)
    + Fixed fullscreen issue in Mac OS X
    + Removed temporarily the color schemes feature (because of the Syntax Highlighting)

**0.7.1**

    + Added file open support (from file manager or terminal).
    + Simplified the source code (mostly the New() and Open() functions).
    + Less memory usage under Linux.
    + Tweaked the textpad-editor.desktop file (only for Linux)

**0.7.2**

	+ Textpad can now open files on Mac OSX.
	+ Changed the Info.plist file
	+ You can now use "make install" on Linux.
	+ Minor name changes.
	+ Reorganized files in the "data" folder.

**0.7.3**

	+ Minor memory usage improvements.
	+ Changed the way the length of a document is calculated.
	+ Prepared source code for Debian packaging (.deb packages).
	
**0.7.4**

    + Reimplemented color schemes.
    + Added Line count.
    + Major code reorganizations.

**0.7.4.1**

	+ Fixed a bug when saving files.
	+ Added a "Recent Files" menu (not functional).
	+ Simplified code.
	






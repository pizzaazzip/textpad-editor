greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets
QT += core gui
QT += printsupport

TEMPLATE = app
TARGET   = textpad-editor

DEPENDPATH += . \
    release
INCLUDEPATH += .

RESOURCES += \
    icons/icons.qrc
	
win32 {
    RC_FILE = data/ms-windows/windows_icon.rc
}

macx { 
    TARGET  = "Textpad Editor"
    ICON    = data/mac-osx/textpad-editor.icns
    RC_FILE = data/mac-osx/textpad-editor.icns
    CONFIG += app_bundle
    QMAKE_INFO_PLIST = data/mac-osx/Info.plist
}

unix:!macx {
    target.path    = /usr/bin
    desktop.path   = /usr/share/applications
    desktop.files += data/linux/textpad-editor.desktop
    INSTALLS      += target desktop
}

HEADERS += \
    src/application.hh \
    src/texteditor.hh \
    src/mainwindow.hh \
    src/settings.hh \
    src/colorschemes.hh \
    src/searchdialog.hh \
    src/ui.hh \
    src/objects.hh \
    src/highlighter.hh

SOURCES += \
    src/main.cc \
    src/application.cc \
    src/mainwindow.cc \
    src/searchdialog.cc \
    src/texteditor.cc \
    src/settings.cc \
    src/colorschemes.cc \
    src/highlighter.cc \
    src/highlighting_modes/vb.cc \
    src/highlighting_modes/vala.cc \
    src/highlighting_modes/python.cc \
    src/highlighting_modes/latex.cc \
    src/highlighting_modes/java.cc \
    src/highlighting_modes/html.cc \
    src/highlighting_modes/css.cc \
    src/highlighting_modes/c.cc \
    src/highlighting_modes/bash.cc \
    src/linenumbers.cc


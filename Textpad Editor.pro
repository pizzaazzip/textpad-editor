greaterThan(QT_MAJOR_VERSION, 4):

TEMPLATE   = app
TARGET     = textpad-editor
VERSION    = 0.8
CODECFORTR = UTF-8

QT += widgets

# Uncomment the following line if you are using Qt 5
#QT += printsupport

win32 {
    TARGET  = "Textpad Editor"
    RC_FILE = Data/Platforms/Windows/windows_icon.rc
}

macx {
    TARGET  = "Textpad Editor"
    ICON    = Data/Platforms/Mac/TextpadEditor.icns
    RC_FILE = Data/Platforms/Mac/TextpadEditor.icns
    CONFIG += app_bundle
    QMAKE_INFO_PLIST = Data/Platforms/Mac/Info.plist
}

unix:!macx {
    target.path    = /usr/bin
    desktop.path   = /usr/share/applications
    desktop.files += Data/Platforms/Linux/textpad-editor.desktop
    INSTALLS      += target desktop
    QMAKESPEC     = linux-g++-32
}

RESOURCES += \
    Resources.qrc

HEADERS += \
    Code/Base/Application.hh \
    Code/Base/Shared.hh \
    Code/MainWindow/MainWindow.hh \
    Code/MainWindow/Widgets.hh \
    Code/TextEdit/CodeEditor/Highlighter.hh \
    Code/TextEdit/SearchDialog/SearchDialog.hh \
    Code/TextEdit/TextEditor.hh

SOURCES += \
    Code/Base/Application.cc \
    Code/Base/Shared.cc \
    Code/MainWindow/MainWindow.cc \
    Code/MainWindow/WindowConstructor.cc \
    Code/MainWindow/WindowSettings.cc \
    Code/TextEdit/CodeEditor/Highlighter.cc \
    Code/TextEdit/CodeEditor/LineNumbers.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/Bash.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/C.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/CSS.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/HTML.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/Java.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/LaTex.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/Python.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/Vala.cc \
    Code/TextEdit/CodeEditor/ProgrammingLanguages/VB.cc \
    Code/TextEdit/SearchDialog/SearchDialog.cc \
    Code/TextEdit/TextEditor.cc \
    Code/Base/Translator.cc

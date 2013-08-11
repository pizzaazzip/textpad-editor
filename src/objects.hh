#ifndef OBJECTS_HH
#define OBJECTS_HH

#include <QUrl>
#include <QLabel>
#include <QPainter>
#include <QAction>
#include <QDialog>
#include <QMenuBar>
#include <QPrinter>
#include <QToolBar>
#include <QCheckBox>
#include <QDateTime>
#include <QLineEdit>
#include <QSettings>
#include <QTextBlock>
#include <QStatusBar>
#include <QGridLayout>
#include <QFontDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTranslator>
#include <QTextCursor>
#include <QTextStream>
#include <QActionGroup>
#include <QApplication>
#include <QPrintDialog>
#include <QSignalMapper>
#include <QPlainTextEdit>
#include <QDesktopServices>

#include <math.h>

class Shared {
public:
    static char CheckOS() {
#ifdef Q_OS_MAC
        return 1;
#endif
#ifdef Q_OS_LINUX
        return 2;
#endif
#ifdef Q_OS_WIN32
        return 3;
#endif
    }
};

#endif

#ifndef SHARED_HH
#define SHARED_HH

#include <math.h>

#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QStyle>
#include <QAction>
#include <QDialog>
#include <QMenuBar>
#include <QPainter>
#include <QPrinter>
#include <QToolBar>
#include <QCheckBox>
#include <QDateTime>
#include <QIODevice>
#include <QMimeData>
#include <QLineEdit>
#include <QSettings>
#include <QTextBlock>
#include <QTextCodec>
#include <QStatusBar>
#include <QGridLayout>
#include <QFontDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextCursor>
#include <QTextStream>
#include <QToolButton>
#include <QTranslator>
#include <QActionGroup>
#include <QApplication>
#include <QLibraryInfo>
#include <QPrintDialog>
#include <QSignalMapper>
#include <QSharedMemory>
#include <QDesktopWidget>
#include <QPlainTextEdit>
#include <QDesktopServices>
#include <QSyntaxHighlighter>
#include <QTextDocumentFragment>

class Shared
{
public:
    /// Settings
    static bool  Highlight_Current_Line;
    static bool  Line_Count;
    static bool  Syntax_Highlighting;
    static bool  Toolbar_Enabled;
    static bool  WordWrap_Enabled;
    static char  Selected_Colorscheme;
    static bool  Statusbar_Enabled;
    static int   Document_Number;
    static int   Window_Number;
    static QFont Font;
    static QString Language;
    static QStringList Recent_Files;

    /// Colorschemes
    static QColor Background;
    static QColor Comments;
    static QColor Foreground;
    static QColor Functions;
    static QColor HighlightLineBackground;
    static QColor HighlightLineForeground;
    static QColor Keywords;
    static QColor Numbers;
    static QColor OtherColor;
    static QColor Quotations;
    static QColor SelectedTextBackground;
    static QColor SelectedTextForeground;
    static QColor LineCountBackgroundColor;
    static QColor LineCountForegroundColor;

    static QString CheckOS();
    static QString GetUserName();
    static void SetColorschemes(char _Selected_Colorscheme);
    static void TranslateStrings();
    static void ReadSettings();
    static void WriteSettings(QMainWindow *Window);

    static int x;
    static int y;

    /// Strings used in the application

    /// File menu
    static QString File;
    static QString New;
    static QString Open;
    static QString Save;
    static QString SaveAs;
    static QString Print;
    static QString Close;
    static QString Quit;

    /// Recent files menu
    static QString OpenRecent;
    static QString ClearAction;

    /// Export Menu
    static QString Export;
    static QString ExportHTML;
    static QString ExportPDF;

    /// Edit menu
    static QString Edit;
    static QString Undo;
    static QString Redo;
    static QString Cut;
    static QString Copy;
    static QString Paste;
    static QString SelectAll;
    static QString SetReadOnly;
    static QString Find;
    static QString FindAndReplace;

    /// Format menu
    static QString Format;
    static QString SelectFont;
    static QString WordWrap;

    /// View menu
    static QString View;
    static QString Advanced;
    static QString ToggleToolbar;
    static QString ToggleStatusbar;
    static QString Fullscreen;
    static QString HighlightLine;
    static QString LineCount;

    /// Languages menu
    static QString LanguageMenu;
    static QString English;
    static QString French;
    static QString German;
    static QString Romanian;
    static QString Russian;
    static QString Spanish;

    /// Modes menu
    static QString Modes;
    static QString NormalMode;
    static QString MinimalMode;
    static QString CustomMode;

    /// Color schemes menu
    static QString ColorSchemes;
    static QString DefaultColorscheme;
    static QString CobaltColorscheme;
    static QString GrayscaleColorscheme;
    static QString KateColorscheme;
    static QString OblivionColorscheme;
    static QString TangoColorscheme;

    /// Highlight Mode menu
    static QString HighlightMode;
    static QString PlainText;
    static QString BashScript;
    static QString C;
    static QString CSS;
    static QString HTML;
    static QString Java;
    static QString LaTeX;
    static QString Python;
    static QString Vala;
    static QString VBasic;

    /// Help menu
    static QString Help;
    static QString Contents;
    static QString AboutTextpad;
    static QString ReportBug;
    static QString AboutQt;
    static QString License;
    static QString Website;
    static QString Donation;

    /// Other strings
    static QString Untitled;
    static QString Words;
    static QString Length;
    static QString Lines;
    static QString SaveChangesToDocument;
    static QString YourChangesWillBeLost;
    static QString AreYouSure;
    static QString YouErasedAllContent;
    static QString Error;
    static QString CannotWriteFile;
    static QString CannotReadFile;
    static QString HelpText;
    static QString RestartApp;

    /// Strings used in the search dialog
    static QString Search;
    static QString Replace;
    static QString ReplaceAll;
    static QString FindWhat;
    static QString ReplaceWith;
    static QString CloseDialog;
    static QString MatchCase;
    static QString Warning;
    static QString NoMatchesFound;
    static QString SearchAndReplace;
    static QString WholeWords;
};

#endif

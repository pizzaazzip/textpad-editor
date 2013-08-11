#ifndef SETTINGS_HH
#define SETTINGS_HH

#include "src/objects.hh"

class Settings : public QObject
{
    Q_OBJECT

public:
    Settings(QWidget *parent = 0);

    char        Colorschemes;
    bool        FullScreen;
    bool        StatusBarVisible;
    bool        ReadOnly;
    bool        ToolbarVisible;
    bool        WordWrapEnabled;
    bool        HighlightCurrentLine;
    bool        LineCount;
    bool        SyntaxHighlight;
    QFont       Font;
    QStringList RecentFiles;

public slots:
    void ReadSettings(QMainWindow *Window);
    void WriteSettings(QMainWindow *Window);
};

#endif

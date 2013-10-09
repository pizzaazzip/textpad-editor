#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Code/MainWindow/Widgets.hh"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    Highlighter  *SyntaxHighlighter;
    TextEditor   *TextEdit;

    _widgets::MainWindow *Widgets;

    bool RestoreToolbar;
    bool RestoreHighlightLine;
    bool FullscreenEnabled;
    bool ReadOnly;

    int   lH;
    int   lW;
    int   lY;
    int   lX;
    int   DocumentNumber;

    bool        DocumentEdited;
    bool        Maximized;
    QPalette    Palette;
    QRect       Geometry;
    QString     DocumentTitle;

public slots:
    /// MainWindow.cc
    void AboutTextpad();
    void ClearRecentFiles();
    void CreateNewWindow(MainWindow *Window);
    void Donate();
    void Find();
    void FixDammToolbar(bool toolbarVisible);
    void NewDocument();
    void OpenDocument();
    void OpenDocumentFromDrop(QString File);
    void OpenRecentFile();
    void OpenWebsite();
    void ReportBug();
    void ShowLicense();
    void SmartSave();
    void UpdateHighlightingMode(short FileType);
    void UpdateRecentFiles();
    void UpdateWindowTitle();
    void ViewHelp();

    /// WindowConstructor.cc
    void ConnectSlots();
    void CreateObjects();
    void LoadWindow();
    void SetupUI();

    /// Settings.cc
    void ApplySettings();
    void ApplySettingsGlobaly();

    void CheckMode();
    void SelectFont();

    void SetColorschemes(int Colorscheme);
    void SetFullscreen();
    void SetHighlightCurrentLine();
    void SetLanguage();
    void SetLineCount();
    void SetReadOnly();
    void SetStatusbar();
    void SetToolbar();
    void SetWordwrap();

    void ToggleFullscreen();
    void ToggleHighlightLine();
    void ToggleLineCount();
    void ToggleMinimalMode();
    void ToggleNormalMode();
    void ToggleReadOnly();
    void ToggleStatusbar();
    void ToggleToolbar();
    void ToggleWordwrap();
    void UpdateColorschemes();

protected:
    void closeEvent(QCloseEvent *Event);

signals:
    void UpdateSettings();
};

#endif

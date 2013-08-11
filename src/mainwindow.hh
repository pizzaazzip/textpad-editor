#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/ui.hh"
#include "src/objects.hh"
#include "src/texteditor.hh"
#include "src/settings.hh"
#include "src/colorschemes.hh"
#include "src/highlighter.hh"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    Settings *Preferences;
    ColorSchemes *Colorschemes;
    Highlighter *SyntaxHighlighter;
    Ui::MainWindow *ui;
    textEditor::MainWindow *TextEditor;
    bool RestoreToolbar;

public slots:
    // MainWindow.cc
    void AboutTextpad();
    void ApplySettings();
    void Donate();
    void Initialize();
    void OpenWebsite();
    void ReportBug();
    void ShowLicense();
    void UpdateHighlightingMode(const char FileType);
    void UpdateWindowTitle();

    // Settings.cc
    void SelectFont();
    void ToggleFullscreen();
    void ToggleHighlightLine();
    void ToggleLineCount();
    void ToggleMinimalMode();
    void ToggleNormalMode();
    void ToggleReadOnly();
    void ToggleStatusbar();
    void ToggleToolbar();
    void ToggleWordwrap();
    void UpdateColorschemes(int Colorscheme);

protected:
    void closeEvent(QCloseEvent *Event);
};

#endif

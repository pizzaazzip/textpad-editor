// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/settings.hh"
#include "src/mainwindow.hh"

Settings::Settings(QWidget *parent): QObject(parent) {}

void Settings::ReadSettings(QMainWindow *Window)
{
    QSettings Configuration("Textpad Editor", "Configuration");

    Configuration.beginGroup("Window Settings");
    if              (Configuration.value("Window.Maximized", false).toBool() == true ) Window->showMaximized();
    else if         (Configuration.value("Window.Maximized", false).toBool() == false) Window->showNormal();
    Window->move    (Configuration.value("Window.Position",  QPoint(150, 150)).toPoint());
    Window->resize  (Configuration.value("Window.Size",      QSize (800, 400)).toSize());
    Configuration.endGroup();

    // Load the font settings
    Configuration.beginGroup("Fonts");

    // This is to make the font readable on Mac OS X
    int FontSize;
    QString FontName;

    if (Shared::CheckOS() == 1) {
        FontSize = 11;
        FontName = "Menlo";
    }
    else {
        FontSize = 10;
        FontName = "Courier";
    }

    Font.setFamily    (Configuration.value("Font.Family",    FontName).toString());
    Font.setPointSize (Configuration.value("Font.Size",      FontSize).toInt());
    Font.setBold      (Configuration.value("Font.Bold",      false).toBool());
    Font.setItalic    (Configuration.value("Font.Italic",    false).toBool());
    Font.setUnderline (Configuration.value("Font.Underline", false).toBool());
    Font.setStrikeOut (Configuration.value("Font.Strikeout", false).toBool());
    Configuration.endGroup();

    // Load other settings
    Configuration.beginGroup("Preferences");
    Colorschemes         = Configuration.value("Preferences.Colorscheme",          1     ).toInt();
    FullScreen           = Configuration.value("Preferences.FullscreenEnabled",    false ).toBool();
    HighlightCurrentLine = Configuration.value("Preferences.HighlightCurrentLine", true  ).toBool();
    LineCount            = Configuration.value("Preferences.LineCountEnabled",     true  ).toBool();
    StatusBarVisible     = Configuration.value("Preferences.StatusbarVisible",     true  ).toBool();
    ToolbarVisible       = Configuration.value("Preferences.ToolbarVisible",       true  ).toBool();
    WordWrapEnabled      = Configuration.value("Preferences.WordWrapEnabled",      true  ).toBool();

    for (int i = 0; i <= 10; i++) {
        QString Token = QString("RecentFile: %1").arg(i);
        QString FilePath = Configuration.value(Token, QString("")).toString();
        if (!FilePath.isEmpty())
            RecentFiles.append(FilePath);
    }
}

void Settings::WriteSettings(QMainWindow *Window)
{
    QSettings Configuration("Textpad Editor", "Configuration");

    // Window Settings
    Configuration.beginGroup("Window");
    Configuration.setValue("Window.Position",  Window->pos());
    Configuration.setValue("Window.Size",      Window->size());
    Configuration.setValue("Window.Maximized", Window->isMaximized());
    Configuration.endGroup();

    // Font settings
    Configuration.beginGroup("Fonts");
    Configuration.setValue("Font.Family",    Font.family());
    Configuration.setValue("Font.Size",      Font.pointSize());
    Configuration.setValue("Font.Bold",      Font.bold());
    Configuration.setValue("Font.Italic",    Font.italic());
    Configuration.setValue("Font.Underline", Font.underline());
    Configuration.setValue("Font.Strikeout", Font.strikeOut());
    Configuration.endGroup();

    // Other settings
    Configuration.beginGroup("Preferences");
    Configuration.setValue("Preferences.Colorscheme",          Colorschemes);
    Configuration.setValue("Preferences.FullscreenEnabled",    FullScreen);
    Configuration.setValue("Preferences.HighlightCurrentLine", HighlightCurrentLine);
    Configuration.setValue("Preferences.LineCountEnabled",     LineCount);
    Configuration.setValue("Preferences.StatusbarVisible",     StatusBarVisible);
    Configuration.setValue("Preferences.ToolbarVisible",       ToolbarVisible);
    Configuration.setValue("Preferences.WordWrapEnabled",      WordWrapEnabled);
    Configuration.endGroup();

    // Save recent files
    for (int i = 0; i < RecentFiles.count(); i++) {
        QString Token    = QString("RecentFile: %1").arg(i);
        QString FilePath = RecentFiles.at(i);
        Configuration.setValue(Token, FilePath);
    }
    for (int i = RecentFiles.count(); i <= 10; i++) {
        QString Token    = QString("RecentFile: %1").arg(i);
        QString FilePath = "";
        Configuration.setValue(Token, FilePath);
    }
}

void MainWindow::SelectFont() {
    QFontDialog *FontDialog = new QFontDialog(this);
    FontDialog->setCurrentFont(Preferences->Font);

    if (FontDialog->exec() == QFontDialog::Accepted) {
        Preferences->Font = FontDialog->selectedFont();
        ApplySettings();
    }
}

void MainWindow::ToggleFullscreen() {
    Preferences->FullScreen = !Preferences->FullScreen;
    ApplySettings();

    // Fullscreen settings
    if (Preferences->FullScreen == false) {
        // Remove the fullscreen toolbar button on Windows & Linux
        if (Shared::CheckOS() != 1) {
            ui->Toolbar->removeAction(ui->FullscreenSeparator);
            ui->Toolbar->removeAction(ui->Fullscreen);
        }
        // Restore the toolbar state on Mac OS X
        else {
            Preferences->ToolbarVisible = RestoreToolbar;
            ui->ToggleToolbar->setEnabled(true);
            ApplySettings();
        }
    }

    else if (Preferences->FullScreen == true) {
        // Add the fullscreen toolbar button on Windows & Linux
        if (Shared::CheckOS() != 1) {
            ui->Toolbar->addAction(ui->FullscreenSeparator);
            ui->Toolbar->addAction(ui->Fullscreen);
        }
        // Hide the toolbar on Mac OS X
        else {
            ui->ToggleToolbar->setEnabled(false);
            if (Preferences->ToolbarVisible == true) {
                RestoreToolbar = true;
                Preferences->ToolbarVisible = false;
                ApplySettings();
            }
            else RestoreToolbar = false;
        }
    }
}

void MainWindow::ToggleHighlightLine() {
    Preferences->HighlightCurrentLine = !Preferences->HighlightCurrentLine;
    ApplySettings();
}

void MainWindow::ToggleLineCount() {
    Preferences->LineCount = !Preferences->LineCount;
    ApplySettings();
}

void MainWindow::ToggleMinimalMode() {
    Preferences->ToolbarVisible   = false;
    Preferences->StatusBarVisible = false;
    ApplySettings();
}

void MainWindow::ToggleNormalMode() {
    Preferences->ToolbarVisible   = true;
    Preferences->StatusBarVisible = true;
    ApplySettings();
}

void MainWindow::ToggleReadOnly() {
    Preferences->ReadOnly = !Preferences->ReadOnly;
    ApplySettings();
}

void MainWindow::ToggleStatusbar() {
    Preferences->StatusBarVisible = !Preferences->StatusBarVisible;
    ApplySettings();
}

void MainWindow::ToggleToolbar() {
    Preferences->ToolbarVisible = !Preferences->ToolbarVisible;
    ApplySettings();
}

void MainWindow::ToggleWordwrap() {
    Preferences->WordWrapEnabled = !Preferences->WordWrapEnabled;
    ApplySettings();
}

void MainWindow::UpdateColorschemes(int Colorscheme) {
    Preferences->Colorschemes = Colorscheme;
    Colorschemes->SetColorscheme(Colorscheme);

    // Change the colorscheme of the text edit
    QPalette Palette;
    Palette = TextEditor->palette();
    Palette.setColor(QPalette::Base, Colorschemes->Background);
    Palette.setColor(QPalette::Text, Colorschemes->Foreground);
    Palette.setColor(QPalette::Highlight, Colorschemes->SelectedBackground);
    Palette.setColor(QPalette::HighlightedText, Colorschemes->SelectedForeground);
    TextEditor->HighlightLineBackground = Colorschemes->HighlightLineBackground;
    TextEditor->setPalette(Palette);
    TextEditor->HighlightCurrentLine();

    // Change the colorschemes of the syntax highlighter
    SyntaxHighlighter->Comments = Colorschemes->Comments;
    SyntaxHighlighter->Functions = Colorschemes->Functions;
    SyntaxHighlighter->Keywords = Colorschemes->Keywords;
    SyntaxHighlighter->Numbers = Colorschemes->Numbers;
    SyntaxHighlighter->OtherColor = Colorschemes->OtherColor;
    SyntaxHighlighter->Quotations = Colorschemes->Qoutations;
    SyntaxHighlighter->setColor();
    SyntaxHighlighter->setLanguage(SyntaxHighlighter->SelectedLanguage);
}

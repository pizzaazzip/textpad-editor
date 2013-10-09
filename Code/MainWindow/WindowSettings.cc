// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/MainWindow/MainWindow.hh"

void MainWindow::ApplySettings() {

    if (TextEdit->Filename.isEmpty()) {
        TextEdit->documentNumber = DocumentNumber;
        TextEdit->setDocumentTitle(Shared::Untitled + QString::number(DocumentNumber));
    }

    // Create some backups of some values (these values are erased while the settings are updated)
    DocumentTitle  = TextEdit->documentTitle();
    DocumentEdited = TextEdit->document()->isModified();

    Shared::ReadSettings();

    UpdateColorschemes();
    SetHighlightCurrentLine();
    SetLineCount();
    SetStatusbar();
    SetToolbar();
    SetWordwrap();

    // Decide if we need to select the "Normal Mode", "Minimal Mode" or "Custom Mode"
    CheckMode();

    // Update the values (Font, document title, modification status, etc) of the TextEdit.
    TextEdit->setFont(Shared::Font);
    TextEdit->setDocumentTitle(DocumentTitle);
    TextEdit->document()->setModified(DocumentEdited);

    // Update the window title
    UpdateWindowTitle();

    // Check which language should we check
    if (Shared::Language == "en")
        Widgets->English->setChecked(true);
    if (Shared::Language == "fr")
        Widgets->French->setChecked(true);
    if (Shared::Language == "de")
        Widgets->German->setChecked(true);
    if (Shared::Language == "ro")
        Widgets->Romanian->setChecked(true);
    if (Shared::Language == "ru")
        Widgets->Russian->setChecked(true);
    if (Shared::Language == "es")
        Widgets->Spanish->setChecked(true);
}

void MainWindow::ApplySettingsGlobaly() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    Shared::WriteSettings(this);
    UpdateSettings();
    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::CheckMode() {
    if (Shared::Statusbar_Enabled && Shared::Toolbar_Enabled) {
        Widgets->NormalMode->setChecked(true);
        return;
    }

    if (!Shared::Statusbar_Enabled && !Shared::Toolbar_Enabled)  {
        Widgets->MinimalMode->setChecked(true);
        return;
    }

    Widgets->CustomMode->setChecked(true);
}

void MainWindow::FixDammToolbar(bool toolbarVisible) {
    Shared::Toolbar_Enabled = toolbarVisible;
    Widgets->ToggleToolbar->setChecked(toolbarVisible);
}

void MainWindow::SelectFont() {
    QFontDialog *FontDialog = new QFontDialog(this);
    FontDialog->setCurrentFont(Shared::Font);

    if (FontDialog->exec() == QFontDialog::Accepted) {
        Shared::Font = FontDialog->selectedFont();
        ApplySettingsGlobaly();
    }
}

void MainWindow::SetColorschemes(int Colorscheme) {
    Shared::Selected_Colorscheme = Colorscheme;
    ApplySettingsGlobaly();
}

void MainWindow::SetFullscreen() {
    Widgets->Fullscreen->setChecked(FullscreenEnabled);

    if (FullscreenEnabled) {
        showFullScreen();

        if (!ReadOnly)
            Widgets->Toolbar->addAction(Widgets->ExtraSeparatorAction);

        Widgets->Toolbar->addAction(Widgets->Fullscreen);
    }

    else {
        showNormal();

        if (!ReadOnly)
            Widgets->Toolbar->removeAction(Widgets->ExtraSeparatorAction);

        Widgets->Toolbar->removeAction(Widgets->Fullscreen);
    }
}

void MainWindow::SetHighlightCurrentLine() {
    TextEdit->Highlight_Current_Line();
    Widgets->HighlightLine->setChecked(Shared::Highlight_Current_Line);
}

void MainWindow::SetLanguage() {
    QAction *Action = qobject_cast<QAction*>(sender());
    QString Language = Action->objectName();
    Language.replace("-menu", "");

    Shared::Language = Language;

    QMessageBox::information(this, " ", Shared::RestartApp);
}

void MainWindow::SetLineCount() {
    TextEdit->setPlainText(TextEdit->toPlainText());
    Widgets->LineCount->setChecked(Shared::Line_Count);
}

void MainWindow::SetReadOnly() {
    TextEdit->setReadOnly(ReadOnly);

    if (ReadOnly) {
        if (Widgets->Find->isChecked())
            Widgets->Find->trigger();

        if (!FullscreenEnabled)
            Widgets->Toolbar->addAction(Widgets->ExtraSeparatorAction);

        Widgets->Toolbar->addAction(Widgets->SetReadOnly);
    }

    else
    {
        if (!FullscreenEnabled)
            Widgets->Toolbar->removeAction(Widgets->ExtraSeparatorAction);

        Widgets->Toolbar->removeAction(Widgets->SetReadOnly);
    }

    Widgets->Undo->setEnabled            (!ReadOnly);
    Widgets->Redo->setEnabled            (!ReadOnly);
    Widgets->Cut->setEnabled             (!ReadOnly);
    Widgets->Paste->setEnabled           (!ReadOnly);
    Widgets->Find->setEnabled            (!ReadOnly);
    Widgets->FindAndReplace->setEnabled  (!ReadOnly);
    Widgets->FindLineEdit->setEnabled    (!ReadOnly);
    Widgets->SetReadOnly->setChecked     ( ReadOnly);
}

void MainWindow::SetStatusbar() {
    if (Shared::Statusbar_Enabled)
        statusBar()->show();
    else
        statusBar()->hide();

    Widgets->ToggleStatusbar->setChecked(Shared::Statusbar_Enabled);
}

void MainWindow::SetToolbar() {
    if (Shared::Toolbar_Enabled)
        Widgets->Toolbar->show();
    else
        Widgets->Toolbar->hide();

    Widgets->ToggleToolbar->setChecked(Shared::Toolbar_Enabled);
}

void MainWindow::SetWordwrap() {
    if (Shared::WordWrap_Enabled)
        TextEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    else
        TextEdit->setWordWrapMode(QTextOption::NoWrap);

    Widgets->WordWrap->setChecked(Shared::WordWrap_Enabled);
}

void MainWindow::ToggleFullscreen() {
    FullscreenEnabled = !FullscreenEnabled;
    RestoreToolbar = Shared::Toolbar_Enabled;

    SetFullscreen();
}

void MainWindow::ToggleHighlightLine() {
    Shared::Highlight_Current_Line = !Shared::Highlight_Current_Line;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleLineCount() {
    Shared::Line_Count = !Shared::Line_Count;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleMinimalMode() {
    Shared::Toolbar_Enabled   = false;
    Shared::Statusbar_Enabled = false;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleNormalMode() {
    Shared::Toolbar_Enabled   = true;
    Shared::Statusbar_Enabled = true;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleReadOnly() {
    ReadOnly = !ReadOnly;
    SetReadOnly();
}

void MainWindow::ToggleStatusbar() {
    Shared::Statusbar_Enabled = !Shared::Statusbar_Enabled;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleToolbar() {
    Shared::Toolbar_Enabled = !Shared::Toolbar_Enabled;
    ApplySettingsGlobaly();
}

void MainWindow::ToggleWordwrap() {
    Shared::WordWrap_Enabled = !Shared::WordWrap_Enabled;
    ApplySettingsGlobaly();
}

void MainWindow::UpdateColorschemes() {
    Shared::SetColorschemes(Shared::Selected_Colorscheme);
    Palette = TextEdit->palette();
    Palette.setColor(QPalette::Base, Shared::Background);
    Palette.setColor(QPalette::Text, Shared::Foreground);
    Palette.setColor(QPalette::Highlight, Shared::SelectedTextBackground);
    Palette.setColor(QPalette::HighlightedText, Shared::SelectedTextForeground);
    TextEdit->setPalette(Palette);

    SyntaxHighlighter->setColor();

    switch(Shared::Selected_Colorscheme) {
    case 1: Widgets->DefaultColorscheme->setChecked   (true); break;
    case 3: Widgets->GrayscaleColorscheme->setChecked (true); break;
    case 2: Widgets->CobaltColorscheme->setChecked    (true); break;
    case 4: Widgets->KateColorscheme->setChecked      (true); break;
    case 5: Widgets->OblivionColorscheme->setChecked  (true); break;
    case 6: Widgets->TangoColorscheme->setChecked     (true); break;
    }

    TextEdit->UpdateLineNumberAreaWidth(TextEdit->document()->blockCount());
}

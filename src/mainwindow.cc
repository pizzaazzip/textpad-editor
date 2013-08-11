// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/mainwindow.hh"
#include "QApplication"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow), TextEditor(new textEditor::MainWindow) {
    Initialize();
}

void MainWindow::closeEvent(QCloseEvent *Event) {
    Preferences->WriteSettings(this);
    if (TextEditor->MaybeSave()) {
        Event->accept();
        return;
    }
    Event->ignore();
}

void MainWindow::AboutTextpad() {
    QString iconLink = "<a href = 'https://launchpad.net/elementaryicons'>Elementary Icon Theme</a>.<br>";

    // Create a string for the messagebox
    QString Message = tr("Copyright (C) 2013 by the Textpad developers.<br>")
            + tr("<br>The icons used in this application come from the ") +  iconLink
            + tr("<br>The program is provided AS IS with NO WARRANTY OF ANY KIND,<br>"
                 "INCLUDING THE WARRANTY OF DESIGN, "
                 "MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.<br><br>"
                 "Read a copy of the <a href = 'http://www.gnu.org/licenses/gpl-3.0.txt'>"
                 "GPL 3.0 License</a> for more information.<br>")
            + tr("<br>This program uses code from the Qt Toolkit, which is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies), "
                 "see <a href = 'http://qt.digia.com//'>qt.digia.com</a> for more information.");

    QMessageBox MessageBox;
    MessageBox.setText("<h2>" + qApp->applicationName() + " " + qApp->applicationVersion() + " (alpha release)</h2>");
    MessageBox.setWindowTitle(tr("About"));
    MessageBox.setInformativeText(Message);
    MessageBox.setIconPixmap(QPixmap(":/app-icon/48x48/textpad-editor.png"));
    MessageBox.setStandardButtons(QMessageBox::Close);
    MessageBox.exec();
}


void MainWindow::ApplySettings() {
    if      (Preferences->FullScreen       == false) { showNormal();        }
    else if (Preferences->FullScreen       == true ) { showFullScreen();    }
    if      (Preferences->StatusBarVisible == false) { statusBar()->hide(); }
    else if (Preferences->StatusBarVisible == true ) { statusBar()->show(); }
    if      (Preferences->ToolbarVisible   == false) { ui->Toolbar->hide(); }
    else if (Preferences->ToolbarVisible   == true ) { ui->Toolbar->show(); }
    if      (Preferences->WordWrapEnabled  == false) { TextEditor->setWordWrapMode(QTextOption::NoWrap); }
    else if (Preferences->WordWrapEnabled  == true ) { TextEditor->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere); }

    // Colorscheme settings
    UpdateColorschemes(Preferences->Colorschemes);
    switch(Preferences->Colorschemes) {
    case 1: ui->DefaultColorscheme->setChecked  (true); break;
    case 2: ui->CobaltColorscheme->setChecked   (true); break;
    case 3: ui->KateColorscheme->setChecked     (true); break;
    case 4: ui->OblivionColorscheme->setChecked (true); break;
    case 5: ui->TangoColorscheme->setChecked    (true); break;
    }

    // Set font properties of the TextEditor
    TextEditor->setFont(Preferences->Font);
    TextEditor->HighlightLine = Preferences->HighlightCurrentLine;
    TextEditor->HighlightCurrentLine();

    // UI Mode settings
    if      ((Preferences->StatusBarVisible == false) & (Preferences->ToolbarVisible == false)) ui->MinimalMode->setChecked (true);
    else if ((Preferences->StatusBarVisible == true ) & (Preferences->ToolbarVisible == true))  ui->NormalMode->setChecked  (true);
    else ui->CustomMode->setChecked(true);

    // Read-only settings
    TextEditor->setReadOnly(Preferences->ReadOnly);
    if (Preferences->ReadOnly == false) {
        ui->Undo->setEnabled           (true);
        ui->Redo->setEnabled           (true);
        ui->Cut->setEnabled            (true);
        ui->Paste->setEnabled          (true);
        ui->FindAndReplace->setEnabled (true);

        ui->Toolbar->removeAction(ui->SetReadOnlySeparator);
        ui->Toolbar->removeAction(ui->SetReadOnly);
    }
    else {
        ui->Undo->setEnabled           (false);
        ui->Redo->setEnabled           (false);
        ui->Cut->setEnabled            (false);
        ui->Paste->setEnabled          (false);
        ui->FindAndReplace->setEnabled (false);

        ui->Toolbar->addAction(ui->SetReadOnlySeparator);
        ui->Toolbar->addAction(ui->SetReadOnly);
    }

    ui->Fullscreen->setChecked      (Preferences->FullScreen);
    ui->HighlightLine->setChecked   (Preferences->HighlightCurrentLine);
    ui->LineCount->setChecked       (Preferences->LineCount);
    ui->ToggleStatusbar->setChecked (Preferences->StatusBarVisible);
    ui->SetReadOnly->setChecked     (Preferences->ReadOnly);
    ui->ToggleToolbar->setChecked   (Preferences->ToolbarVisible);
    ui->WordWrap->setChecked        (Preferences->WordWrapEnabled);

    // Line count settings
    TextEditor->LineCountEnabled = Preferences->LineCount;
    TextEditor->setPlainText(TextEditor->toPlainText());

    Preferences->WriteSettings(this);
}

void MainWindow::Donate() {
    QDesktopServices::openUrl(QUrl("http://textpad-editor.sf.net/donate"));
}

void MainWindow::Initialize() {
    ui->SetupUI(this);

    setCentralWidget(TextEditor);
    statusBar()->addPermanentWidget(TextEditor->DocumentStatus);

    connect(ui->AboutQt,         SIGNAL(triggered()),   qApp,                     SLOT(aboutQt()));
    connect(ui->AboutTextpad,    SIGNAL(triggered()),   this,                     SLOT(AboutTextpad()));
    connect(ui->Donation,        SIGNAL(triggered()),   this,                     SLOT(Donate()));
    connect(ui->Fullscreen,      SIGNAL(triggered()),   this,                     SLOT(ToggleFullscreen()));
    connect(ui->HighlightLine,   SIGNAL(triggered()),   this,                     SLOT(ToggleHighlightLine()));
    connect(ui->License,         SIGNAL(triggered()),   this,                     SLOT(ShowLicense()));
    connect(ui->LineCount,       SIGNAL(triggered()),   this,                     SLOT(ToggleLineCount()));
    connect(ui->MinimalMode,     SIGNAL(triggered()),   this,                     SLOT(ToggleMinimalMode()));
    connect(ui->NormalMode,      SIGNAL(triggered()),   this,                     SLOT(ToggleNormalMode()));
    connect(ui->Quit,            SIGNAL(triggered()),   this,                     SLOT(close()));
    connect(ui->ReportBug,       SIGNAL(triggered()),   this,                     SLOT(ReportBug()));
    connect(ui->SelectFont,      SIGNAL(triggered()),   this,                     SLOT(SelectFont()));
    connect(ui->SetReadOnly,     SIGNAL(triggered()),   this,                     SLOT(ToggleReadOnly()));
    connect(ui->ToggleStatusbar, SIGNAL(triggered()),   this,                     SLOT(ToggleStatusbar()));
    connect(ui->ToggleToolbar,   SIGNAL(triggered()),   this,                     SLOT(ToggleToolbar()));
    connect(ui->Website,         SIGNAL(triggered()),   this,                     SLOT(OpenWebsite()));
    connect(ui->WordWrap,        SIGNAL(triggered()),   this,                     SLOT(ToggleWordwrap()));

    connect(ui->Copy,            SIGNAL(triggered()),   TextEditor,               SLOT(copy()));
    connect(ui->Cut,             SIGNAL(triggered()),   TextEditor,               SLOT(cut()));
    connect(ui->New,             SIGNAL(triggered()),   TextEditor,               SLOT(New()));
    connect(ui->Open,            SIGNAL(triggered()),   TextEditor,               SLOT(Open()));
    connect(ui->Paste,           SIGNAL(triggered()),   TextEditor,               SLOT(paste()));
    connect(ui->Print,           SIGNAL(triggered()),   TextEditor,               SLOT(Print()));
    connect(ui->Redo,            SIGNAL(triggered()),   TextEditor,               SLOT(redo()));
    connect(ui->Save,            SIGNAL(triggered()),   TextEditor,               SLOT(Save()));
    connect(ui->SaveAs,          SIGNAL(triggered()),   TextEditor,               SLOT(SaveAs()));
    connect(ui->SelectAll,       SIGNAL(triggered()),   TextEditor,               SLOT(selectAll()));
    connect(ui->Undo,            SIGNAL(triggered()),   TextEditor,               SLOT(undo()));

    connect(ui->FindAndReplace,  SIGNAL(triggered()),   TextEditor->SearchDialog, SLOT(show()));

    connect(TextEditor, SIGNAL(requestHighlightByExtension(char)),      this, SLOT(UpdateHighlightingMode(char)));
    connect(TextEditor, SIGNAL(requestUpdateTitle()),                   this, SLOT(UpdateWindowTitle()));

    Preferences = new Settings(this);
    Preferences->ReadSettings(this);
    Preferences->ReadOnly = false;
    RestoreToolbar = Preferences->ToolbarVisible;

    Colorschemes = new ColorSchemes(this);

    TextEditor->setFont(Preferences->Font);
    TextEditor->setMinimumSize(400, 200);

    SyntaxHighlighter = new Highlighter(TextEditor->document());

    connect(ui->ColorSignalMapper,     SIGNAL(mapped(int)), this,              SLOT(UpdateColorschemes(int)));
    connect(ui->HighlightSignalMapper, SIGNAL(mapped(int)), SyntaxHighlighter, SLOT(setLanguage(int)));

    ApplySettings();

    if (Shared::CheckOS() == 1) {
        Preferences->FullScreen = !Preferences->FullScreen;
        ToggleFullscreen();
    }
}

void MainWindow::OpenWebsite() {
    QDesktopServices::openUrl(QUrl("http://sf.net/p/textpad-editor"));
}

void MainWindow::ReportBug() {
    QDesktopServices::openUrl(QUrl("http://sf.net/p/textpad-editor/discussion/bugs/"));
}

void MainWindow::ShowLicense() {
    QDesktopServices::openUrl(QUrl("http://www.gnu.org/licenses/gpl-3.0.txt"));
}

void MainWindow::UpdateHighlightingMode(const char FileType) {
    SyntaxHighlighter->setLanguage(FileType);

    switch (FileType) {
    case 1: ui->PlainText->setChecked  (true); break;
    case 2: ui->BashScript->setChecked (true); break;
    case 3: ui->C->setChecked          (true); break;
    case 4: ui->CSS->setChecked        (true); break;
    case 5: ui->HTML->setChecked       (true); break;
    case 6: ui->Java->setChecked       (true); break;
    case 7: ui->LaTeX->setChecked      (true); break;
    case 8: ui->Python->setChecked     (true); break;
    }
}

void MainWindow::UpdateWindowTitle() {
    setWindowTitle(TextEditor->documentTitle() + " - Textpad");
}

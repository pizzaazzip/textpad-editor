// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/MainWindow/MainWindow.hh"

void MainWindow::ConnectSlots() {
    connect(Widgets->AboutQt,         SIGNAL(triggered()),   qApp,                     SLOT(aboutQt()));
    connect(Widgets->AboutTextpad,    SIGNAL(triggered()),   this,                     SLOT(AboutTextpad()));
    connect(Widgets->Contents,        SIGNAL(triggered()),   this,                     SLOT(ViewHelp()));
    connect(Widgets->Donation,        SIGNAL(triggered()),   this,                     SLOT(Donate()));
    connect(Widgets->Find,            SIGNAL(triggered()),   this,                     SLOT(Find()));
    connect(Widgets->Fullscreen,      SIGNAL(triggered()),   this,                     SLOT(ToggleFullscreen()));
    connect(Widgets->HighlightLine,   SIGNAL(triggered()),   this,                     SLOT(ToggleHighlightLine()));
    connect(Widgets->License,         SIGNAL(triggered()),   this,                     SLOT(ShowLicense()));
    connect(Widgets->LineCount,       SIGNAL(triggered()),   this,                     SLOT(ToggleLineCount()));
    connect(Widgets->MinimalMode,     SIGNAL(triggered()),   this,                     SLOT(ToggleMinimalMode()));
    connect(Widgets->NormalMode,      SIGNAL(triggered()),   this,                     SLOT(ToggleNormalMode()));
    connect(Widgets->Close,           SIGNAL(triggered()),   this,                     SLOT(close()));
    connect(Widgets->Quit,            SIGNAL(triggered()),   qApp,                     SLOT(closeAllWindows()));
    connect(Widgets->ReportBug,       SIGNAL(triggered()),   this,                     SLOT(ReportBug()));
    connect(Widgets->SelectFont,      SIGNAL(triggered()),   this,                     SLOT(SelectFont()));
    connect(Widgets->SetReadOnly,     SIGNAL(triggered()),   this,                     SLOT(ToggleReadOnly()));
    connect(Widgets->ToggleStatusbar, SIGNAL(triggered()),   this,                     SLOT(ToggleStatusbar()));
    connect(Widgets->ToggleToolbar,   SIGNAL(triggered()),   this,                     SLOT(ToggleToolbar()));
    connect(Widgets->Website,         SIGNAL(triggered()),   this,                     SLOT(OpenWebsite()));
    connect(Widgets->WordWrap,        SIGNAL(triggered()),   this,                     SLOT(ToggleWordwrap()));
    connect(Widgets->ClearAction,     SIGNAL(triggered()),   this,                     SLOT(ClearRecentFiles()));
    connect(Widgets->Copy,            SIGNAL(triggered()),   TextEdit,                 SLOT(copy()));
    connect(Widgets->Cut,             SIGNAL(triggered()),   TextEdit,                 SLOT(cut()));
    connect(Widgets->ExportHTML,      SIGNAL(triggered()),   TextEdit,                 SLOT(ExportHTML()));
    connect(Widgets->ExportPDF,       SIGNAL(triggered()),   TextEdit,                 SLOT(ExportPDF()));
    connect(Widgets->New,             SIGNAL(triggered()),   TextEdit,                 SLOT(New()));
    connect(Widgets->Open,            SIGNAL(triggered()),   TextEdit,                 SLOT(Open()));
    connect(Widgets->Paste,           SIGNAL(triggered()),   TextEdit,                 SLOT(paste()));
    connect(Widgets->Print,           SIGNAL(triggered()),   TextEdit,                 SLOT(Print()));
    connect(Widgets->Redo,            SIGNAL(triggered()),   TextEdit,                 SLOT(redo()));
    connect(Widgets->Save,            SIGNAL(triggered()),   TextEdit,                 SLOT(Save()));
    connect(Widgets->SaveAs,          SIGNAL(triggered()),   TextEdit,                 SLOT(SaveAs()));
    connect(Widgets->SelectAll,       SIGNAL(triggered()),   TextEdit,                 SLOT(selectAll()));
    connect(Widgets->Undo,            SIGNAL(triggered()),   TextEdit,                 SLOT(undo()));
    connect(Widgets->FindAndReplace,  SIGNAL(triggered()),   TextEdit->SearchDialog,   SLOT(show()));
    connect(Widgets->Toolbar,         SIGNAL(visibilityChanged(bool)), this,           SLOT(FixDammToolbar(bool)));
    connect(Widgets->FindLineEdit,    SIGNAL(textChanged(QString)),
            TextEdit->SearchDialog->FindLineEdit, SLOT(setText(QString)));
    connect(TextEdit->SearchDialog->FindLineEdit, SIGNAL(textChanged(QString)),
            Widgets->FindLineEdit,    SLOT(setText(QString)));

    connect(TextEdit, SIGNAL(modificationChanged(bool)),              this, SLOT(SmartSave()));
    connect(TextEdit, SIGNAL(textChanged()),                          this, SLOT(UpdateWindowTitle()));
    connect(TextEdit, SIGNAL(requestHighlightByExtension(short)),     this, SLOT(UpdateHighlightingMode(short)));
    connect(TextEdit, SIGNAL(requestUpdateTitle()),                   this, SLOT(UpdateWindowTitle()));
    connect(TextEdit, SIGNAL(requestNew()),                           this, SLOT(NewDocument()));
    connect(TextEdit, SIGNAL(requestOpen()),                          this, SLOT(OpenDocument()));
    connect(TextEdit, SIGNAL(requestOpenDocumentFromDrop(QString)),   this, SLOT(OpenDocumentFromDrop(QString)));

    connect(Widgets->ColorSignalMapper,     SIGNAL(mapped(int)), this,              SLOT(SetColorschemes(int)));
    connect(Widgets->HighlightSignalMapper, SIGNAL(mapped(int)), SyntaxHighlighter, SLOT(setLanguage(int)));

    connect(Widgets->English,  SIGNAL(triggered()), this, SLOT(SetLanguage()));
    connect(Widgets->French,   SIGNAL(triggered()), this, SLOT(SetLanguage()));
    connect(Widgets->German,   SIGNAL(triggered()), this, SLOT(SetLanguage()));
    connect(Widgets->Romanian, SIGNAL(triggered()), this, SLOT(SetLanguage()));
    connect(Widgets->Russian,  SIGNAL(triggered()), this, SLOT(SetLanguage()));
    connect(Widgets->Spanish,  SIGNAL(triggered()), this, SLOT(SetLanguage()));

    connect(Widgets->English,  SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
    connect(Widgets->French,   SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
    connect(Widgets->German,   SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
    connect(Widgets->Romanian, SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
    connect(Widgets->Russian,  SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
    connect(Widgets->Spanish,  SIGNAL(triggered()), this, SLOT(ApplySettingsGlobaly()));
}

void MainWindow::CreateObjects() {
    Shared::ReadSettings();

    TextEdit = new TextEditor(this);
    SyntaxHighlighter = new Highlighter(TextEdit->document());
}

void MainWindow::LoadWindow() {
    CreateObjects();
    SetupUI();
    ConnectSlots();
}

void MainWindow::SetupUI() {
    for (int i = 0; i < Widgets->Max_Recent_Files; ++i) {
        Widgets->RecentFilesAction[i] = new QAction(this);
        Widgets->RecentFilesAction[i]->setVisible(false);
        connect(Widgets->RecentFilesAction[i], SIGNAL(triggered()), this, SLOT(OpenRecentFile()));
    }

    Widgets->SetupUI(this);

    setCentralWidget(TextEdit);
    statusBar()->addPermanentWidget(TextEdit->DocumentStatus);
    DocumentNumber = Shared::Document_Number;
    UpdateHighlightingMode(1);

    FullscreenEnabled = false;
    ReadOnly = false;
    ApplySettings();
}

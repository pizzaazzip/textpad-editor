// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/MainWindow/MainWindow.hh"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), Widgets(new _widgets::MainWindow) {
    setAttribute(Qt::WA_DeleteOnClose);
    setObjectName("MainWindow");

    LoadWindow();
    showNormal();
}

void MainWindow::ClearRecentFiles() {
    Shared::Recent_Files.clear();

    QSettings Settings("Textpad Editor", "Recent Files");
    Settings.setValue("RecentFileList", Shared::Recent_Files);

    UpdateRecentFiles();

    Widgets->ClearAction->setEnabled(false);
}

void MainWindow::closeEvent(QCloseEvent *Event) {
    Shared::WriteSettings(this);

    if (TextEdit->MaybeSave()) {
        Event->accept();
        return;
    }

    Event->ignore();
}

void MainWindow::AboutTextpad() {
    QFile File(":/HTML/Resources/HTML/" + Shared::Language + ".html");
    File.open(QFile::ReadOnly);

    QString Message = QLatin1String(File.readAll());
    Message.replace("[VERSION HERE]", qApp->applicationVersion());

    QMessageBox MessageBox;
    MessageBox.setText("");
    MessageBox.setInformativeText(Message);
    MessageBox.setWindowTitle(" ");
    MessageBox.setIconPixmap(QPixmap(":/Icons/Resources/Icons/96x96/TextpadEditor.png"));
    MessageBox.setStandardButtons(QMessageBox::Ok);
    MessageBox.exec();
}

void MainWindow::CreateNewWindow(MainWindow *Window) {
    qApp->setOverrideCursor(Qt::WaitCursor);

    connect(Window, SIGNAL(UpdateSettings()), this,   SLOT(ApplySettings()));
    connect(this,   SIGNAL(UpdateSettings()), Window, SLOT(ApplySettings()));

    foreach(QWidget *Widget, QApplication::topLevelWidgets()) {
        if(Widget->objectName() == "MainWindow") {
            connect(Widget, SIGNAL(UpdateSettings()), Window, SLOT(ApplySettings()));
            connect(Window, SIGNAL(UpdateSettings()), Widget, SLOT(ApplySettings()));
        }
    }

    if (Window->TextEdit->Filename.isEmpty())
        ++Shared::Document_Number;

    if (width() < (qApp->desktop()->width() / 8) * 6)
        Window->resize(width(), height());
    else
        Window->resize(800, 400);

    int Space = (50 * (Shared::Window_Number + 1) / ((Shared::Window_Number * 2) + 1));
    Window->move(x() + Space, y() + Space);

    Window->show();
    ++Shared::Window_Number;

    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::Donate() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    QDesktopServices::openUrl(QUrl("http://textpad-editor.sf.net/"));
    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::Find() {
    qApp->setOverrideCursor(Qt::WaitCursor);

    if (Widgets->ControlLineEdit->isVisible()) {
        QTextDocument::FindFlags Flags;
        if (TextEdit->SearchDialog->MatchCaseCheckbox->isChecked())
            Flags |= QTextDocument::FindCaseSensitively;

        if (TextEdit->SearchDialog->WholeWordsCheckbox->isChecked())
            Flags |= QTextDocument::FindWholeWords;

        QList<QTextEdit::ExtraSelection> ExtraSelections;
        TextEdit->moveCursor(QTextCursor::End);

        while (TextEdit->find(Widgets->FindLineEdit->text(), Flags | QTextDocument::FindBackward)) {
            QTextEdit::ExtraSelection Selection;
            Selection.format.setBackground(QColor(Qt::yellow));
            Selection.format.setForeground(QColor(Qt::black));
            Selection.cursor = TextEdit->textCursor();
            ExtraSelections.append(Selection);
        }

        TextEdit->setExtraSelections(ExtraSelections);
    }

    if (Widgets->Find->isChecked()) {
        if (FullscreenEnabled) {
            Widgets->Toolbar->removeAction(Widgets->ExtraSeparatorAction);
            Widgets->Toolbar->removeAction(Widgets->Fullscreen);

            Widgets->Toolbar->addAction(Widgets->ControlLineEdit);
            Widgets->Toolbar->addAction(Widgets->Spacer2Action);

            Widgets->Toolbar->addAction(Widgets->ExtraSeparatorAction);
            Widgets->Toolbar->addAction(Widgets->Fullscreen);
        }

        else {
            Widgets->Toolbar->addAction(Widgets->ControlLineEdit);
            Widgets->Toolbar->addAction(Widgets->Spacer2Action);
        }

        // Create a backup of the Highlight_Current_Line value and disable it.
        RestoreHighlightLine = Shared::Highlight_Current_Line;
        Shared::Highlight_Current_Line = false;
        Widgets->HighlightLine->setEnabled(false);
        Widgets->HighlightLine->setChecked(false);
        TextEdit->Highlight_Current_Line();
    }

    if  (!Widgets->Find->isChecked()) {
        Widgets->Toolbar->removeAction(Widgets->ControlLineEdit);
        Widgets->Toolbar->removeAction(Widgets->Spacer2Action);

        Widgets->FindLineEdit->clear();
        TextEdit->SearchDialog->FindLineEdit->clear();

        Shared::Highlight_Current_Line = RestoreHighlightLine;
        Widgets->HighlightLine->setEnabled(true);
        Widgets->HighlightLine->setChecked(Shared::Highlight_Current_Line);
        TextEdit->Highlight_Current_Line();
    }
    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::NewDocument() {
    MainWindow *mainWindow = new MainWindow;
    CreateNewWindow(mainWindow);
}

void MainWindow::OpenDocument() {
    QString File = QFileDialog::getOpenFileName(this, Shared::Open, QDir::homePath());

    if  (!File.isEmpty()) {}
    if (TextEdit->Filename.isEmpty() && !TextEdit->document()->isModified())
        TextEdit->OpenFile(File);

    else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->TextEdit->OpenFile(File);
        CreateNewWindow(mainWindow);
    }
}

void MainWindow::OpenDocumentFromDrop(QString File) {    
    if (TextEdit->Filename.isEmpty() && !TextEdit->document()->isModified())
        TextEdit->OpenFile(File);

    else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->TextEdit->OpenFile(File);
        CreateNewWindow(mainWindow);
    }
}

void MainWindow::OpenRecentFile() {
    QAction *Action = qobject_cast<QAction*>(sender());
    QString File = Action->data().toString();

    if (TextEdit->Filename.isEmpty() && !TextEdit->document()->isModified())
        TextEdit->OpenFile(File);

    else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->TextEdit->OpenFile(File);
        CreateNewWindow(mainWindow);
    }
}

void MainWindow::OpenWebsite() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    QDesktopServices::openUrl(QUrl("http://sf.net/p/textpad-editor"));
    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::ReportBug() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    QDesktopServices::openUrl(QUrl("http://sf.net/p/textpad-editor/discussion/bugs/"));
    qApp->setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::SmartSave() {
    if (!ReadOnly) {
        if (!TextEdit->document()->toPlainText().isEmpty()) {
            if (!TextEdit->document()->isModified())
                Widgets->Save->setEnabled(false);
            else
                Widgets->Save->setEnabled(true);
        }
    }
}

void MainWindow::ShowLicense() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    QDesktopServices::openUrl(QUrl("http://www.gnu.org/licenses/gpl-3.0.txt"));
    qApp->restoreOverrideCursor();
}

void MainWindow::UpdateHighlightingMode(short FileType) {
    SyntaxHighlighter->setLanguage(FileType);

    switch (FileType) {
    case 1:  Widgets->PlainText->setChecked  (true); break;
    case 2:  Widgets->BashScript->setChecked (true); break;
    case 3:  Widgets->C->setChecked          (true); break;
    case 4:  Widgets->CSS->setChecked        (true); break;
    case 5:  Widgets->HTML->setChecked       (true); break;
    case 6:  Widgets->Java->setChecked       (true); break;
    case 7:  Widgets->LaTeX->setChecked      (true); break;
    case 8:  Widgets->Python->setChecked     (true); break;
    case 9:  Widgets->Vala->setChecked       (true); break;
    case 10: Widgets->VBasic->setChecked     (true); break;
    }
}

void MainWindow::UpdateRecentFiles() {
    QSettings Settings("Textpad Editor", "Recent Files");
    Shared::Recent_Files = Settings.value("RecentFileList").toStringList();

    int numRecentFiles = qMin(Shared::Recent_Files.size(), (int)Widgets->Max_Recent_Files);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString Text = QString::number(i + 1) + ". " + QFileInfo(Shared::Recent_Files[i]).fileName();
        Widgets->RecentFilesAction[i]->setText(Text);
        Widgets->RecentFilesAction[i]->setData(Shared::Recent_Files[i]);
        Widgets->RecentFilesAction[i]->setVisible(true);
    }

    for (int j = numRecentFiles; j < Widgets->Max_Recent_Files; ++j)
        Widgets->RecentFilesAction[j]->setVisible(false);
}

void MainWindow::UpdateWindowTitle() {
    QString Title = TextEdit->documentTitle();

    if (TextEdit->document()->isModified())
        Title = "* " + TextEdit->documentTitle();

    setWindowTitle(Title + " - Textpad");

    QSettings Settings("Textpad Editor", "Recent Files");
    Shared::Recent_Files = Settings.value("RecentFileList").toStringList();

    if (!TextEdit->Filename.isEmpty()) {
        Shared::Recent_Files.removeAll(TextEdit->Filename);
        Shared::Recent_Files.prepend(TextEdit->Filename);

        while (Shared::Recent_Files.size() > Widgets->Max_Recent_Files)
            Shared::Recent_Files.removeLast();

        Settings.setValue("RecentFileList", Shared::Recent_Files);
    }

    foreach (QWidget *Widget, QApplication::topLevelWidgets()) {
        MainWindow *MainWin = qobject_cast<MainWindow *>(Widget);
        if (MainWin)
            MainWin->UpdateRecentFiles();
    }

    if (Shared::Recent_Files.size() > 0)
        Widgets->ClearAction->setEnabled(true);
    else
        Widgets->ClearAction->setEnabled(false);
}

void MainWindow::ViewHelp()
{
    QMessageBox MessageBox;
    MessageBox.setText(" ");
    MessageBox.setInformativeText(Shared::HelpText);
    MessageBox.setWindowTitle(" ");
    MessageBox.setIconPixmap(QPixmap(":/Icons/Resources/Icons/48x48/TextpadEditor.png"));
    MessageBox.setStandardButtons(QMessageBox::Ok);
    MessageBox.exec();
}

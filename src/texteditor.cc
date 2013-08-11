// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/texteditor.hh"

TextEditor::TextEditor(QWidget *parent): QPlainTextEdit(parent) {
    // Create the DocumentStatusLabel (for word count, length and lines)
    DocumentStatus = new QLabel(this);
    DocumentStatus->setAlignment(Qt::AlignRight);

    // Create a new FindDialog
    SearchDialog = new FindDialog(this);
    SearchDialog->SetTextEdit(this);

    // Create a new LineCountArea (for line numbers)
    LineCountArea = new LineNumberArea(this);

    connect(this, SIGNAL(textChanged()),            this, SLOT(UpdateDocumentStatus()));
    connect(this, SIGNAL(blockCountChanged(int)),   this, SLOT(UpdateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(cursorPositionChanged()),  this, SLOT(HighlightCurrentLine()));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(UpdateLineNumberArea(QRect,int)));

    UpdateLineNumberAreaWidth(0);
}

bool TextEditor::MaybeSave() {
    // Check if we need to alert the user
    if (document()->isModified()) {
        int Return;

        // Create a simple messagebox in Linux and Windows
        if (Shared::CheckOS() != 1)
            Return = QMessageBox::warning(this, tr("Warning"),
                                          tr("Do you want to save the changes made to the document '%1'?").arg(documentTitle()),
                                          QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        // Create a Mac OS X style messagebox on Mac OSX
        else {
            QMessageBox MessageBox;
            MessageBox.setText(tr("Do you want to save the changes made to the document '%1'?").arg(documentTitle()));
            MessageBox.setInformativeText(tr("Your changes will be lost if you don't save them."));
            MessageBox.setIconPixmap(QPixmap(":/app-icon/48x48/textpad-editor.png"));
            MessageBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel | QMessageBox::Save);
            Return = MessageBox.exec();
        }

        if      (Return == QMessageBox::Cancel)  return false;
        else if (Return == QMessageBox::Save)    return Save();
    }
    return true;
}

bool TextEditor::Save() {
    if      ( FileName.isEmpty()) return SaveAs();
    else if (!FileName.isEmpty()) return SaveFile(FileName);
    return false;
}

bool TextEditor::SaveAs() {
    return SaveFile(QFileDialog::getSaveFileName(this, tr("Save As.."), QDir::homePath()));
}

bool TextEditor::SaveFile(const QString FileLocation) {
    // Check that the file location is valid
    if (!FileLocation.isEmpty()) {
        QFile File(FileLocation);
        if (File.open(QFile::WriteOnly)) {
            // Write the file
            QTextStream Out(&File);
            Out << toPlainText();
            File.close();
            requestUpdateRecentFiles(true, FileLocation);

            // Setup the application
            SetupFile();
            return true;
        }
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(FileLocation)
                             .arg(File.errorString()));
    }
    return false;
}

void TextEditor::New() {
    // Check if we need to save the current document
    if (MaybeSave()) {
        // Clear the text edit and the filename (so we can use Save As)
        FileName.clear();
        clear();
        // Setup the application
        SetupFile();
    }
}

void TextEditor::Open() {
    OpenFile(QFileDialog::getOpenFileName(this, tr("Open"), QDir::homePath()));
}

void TextEditor::OpenFile(const QString FileLocation) {
    // Check that the location is valid
    if (!FileLocation.isEmpty()) {
        // Check if we need to save the document
        if (MaybeSave()) {
            QFile File(FileLocation);

            if (!File.exists()) {
                requestUpdateRecentFiles(false, FileLocation);
                QMessageBox::warning(this, tr("File not found"),
                                     tr("The ghost in the system moved '%1' to another place (or deleted it)")
                                     .arg(FileLocation));
                return;
            }

            if (File.open(QFile::ReadOnly | QFile::WriteOnly | QFile::ReadWrite)) {
                // Load the opened file
                QTextStream InputFile(&File);
                setPlainText(InputFile.readAll());
                FileName = FileLocation;
                SetupFile();
                requestUpdateRecentFiles(true, FileLocation);
                return;
            }

            QMessageBox::warning(this, tr("Error"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(FileLocation)
                                 .arg(File.errorString()));
        }
    }
}

void TextEditor::Print() {
    // Print the current document
    QPrinter Printer;
    QPrintDialog *Dialog = new QPrintDialog(&Printer, this);

    if (Dialog->exec() == QDialog::Accepted)
        document()->print(&Printer);
}

void TextEditor::SetupFile() {
    document()->setModified(false);

    // Change the window title and the statusbar depending on the file
    if (!FileName.isEmpty()) {
        setStatusTip(FileName);
        QFile File(FileName);
        setDocumentTitle(QFileInfo(File).fileName());
    }
    else if (FileName == "") {
        setStatusTip(tr("Unsaved Document"));
        setDocumentTitle(tr("Untitled"));
    }

    // Match the file with a file type (if applicable)
    HighlightByExtension();
    // Update the MainWindow title
    requestUpdateTitle();
}

void TextEditor::UpdateDocumentStatus() {
    // Count the number of words
    int WordCount = toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();

    // Calculate the length of the document and use the best size unit
    char Byte = 1;
    short Kilobyte = 1024;
    int Megabyte = Kilobyte * Kilobyte;

    float Length = toPlainText().length();
    QString UnitString;

    // Calculate the best unit for the length of the document
    if ((Length >= false) & (Length < Kilobyte)) {
        Length /= Byte;
        UnitString = " bytes";
    }
    else if ((Length > Kilobyte) & (Length < Megabyte)) {
        Length /= Kilobyte;
        UnitString = " KB";
    }
    else if ((Length > Megabyte)) {
        Length /= Megabyte;
        UnitString = " MB";
    }

    // Round the length to two decimal places
    float RoundedLength = floorf(Length * 100 + 0.5) / 100;

    // Set the document status label
    QString WordCountString = tr("Words: ")  + QString::number(WordCount);
    QString LengthString    = tr("Length: ") + QString::number(RoundedLength) + UnitString;
    QString LineCountString = tr("Lines: ")  + QString::number(document()->blockCount());
    DocumentStatus->setText(LengthString + "    " + WordCountString + "    " + LineCountString);
}

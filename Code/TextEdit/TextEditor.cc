// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/TextEditor.hh"
#include "QInputDialog"

TextEditor::TextEditor(QWidget *parent): QPlainTextEdit(parent) {
    setMinimumSize(400, 200);

    DocumentStatus = new QLabel(this);
    DocumentStatus->setAlignment(Qt::AlignVCenter);

    SearchDialog = new FindDialog(this);
    SearchDialog->SetTextEdit(this);

    LineCountArea = new LineNumberArea(this);

    connect(this, SIGNAL(textChanged()),            this, SLOT(UpdateDocumentStatus()));
    connect(this, SIGNAL(blockCountChanged(int)),   this, SLOT(UpdateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(cursorPositionChanged()),  this, SLOT(Highlight_Current_Line()));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(UpdateLineNumberArea(QRect,int)));

    UpdateLineNumberAreaWidth(0);
    setAcceptDrops(true);

    Size = 0;
    Counter = 0;
    Start = 0;
    End = 0;
}

bool TextEditor::MaybeSave() {
    if (document()->isModified()) {
        if (Filename.isEmpty()) {
            int Return;
            setDocumentTitle(Shared::Untitled + QString::number(documentNumber));

            QMessageBox MessageBox;
            MessageBox.setText(Shared::SaveChangesToDocument.arg(documentTitle()));
            MessageBox.setInformativeText(Shared::YourChangesWillBeLost);
            MessageBox.setWindowTitle(" ");
            MessageBox.setIconPixmap(QPixmap(":/Icons/Resources/Icons/48x48/TextpadEditor.png"));
            MessageBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel | QMessageBox::Save);
            Return = MessageBox.exec();

            if      (Return == QMessageBox::Cancel)  return false;
            else if (Return == QMessageBox::Save)    return Save();
        }

        else
            if (toPlainText().isEmpty()) {
                int Return;

                QMessageBox MessageBox;
                MessageBox.setText(Shared::AreYouSure);
                MessageBox.setInformativeText(Shared::YouErasedAllContent);
                MessageBox.setWindowTitle(" ");
                MessageBox.setIconPixmap(QPixmap(":/Icons/Resources/Icons/48x48/TextpadEditor.png"));
                MessageBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel | QMessageBox::Save);
                MessageBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
                Return = MessageBox.exec();

                if (Return == QMessageBox::Cancel)
                    return false;
                if (Return == QMessageBox::Discard)
                    return true;
            }

            else
                return Save();
    }
    return true;
}

bool TextEditor::Save() {
    if       ( Filename.isEmpty()) return SaveAs();
    else if  (!Filename.isEmpty()) return SaveFile(Filename);
    return false;
}

bool TextEditor::SaveAs() {
    return SaveFile(QFileDialog::getSaveFileName(this, Shared::SaveAs, QDir::homePath()));
}

bool TextEditor::SaveFile(const QString FileLocation) {
    if  (!FileLocation.isEmpty()) {
        QFile File(FileLocation);
        if (File.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qApp->setOverrideCursor(Qt::WaitCursor);
            File.write(document()->toPlainText().toUtf8());
            File.close();
            Filename = File.fileName();
            SetupFile();
            qApp->restoreOverrideCursor();
            return true;
        }

        QMessageBox::warning(this, Shared::Error,
                             Shared::CannotWriteFile.arg(FileLocation).arg(File.errorString()));
    }
    return false;
}

int TextEditor::CountWords() {
    // This is a very precise way of counting words, but it can consume lot of CPU and RAM on large files
    if (toPlainText().length() > 10000)
        return toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();

    // This method is not very precise, but it does not consume too much CPU and RAM
    {
        QString text = toPlainText();
        if (text.length() < Size)
        {
            Size = 0;
            Counter = 0;
            Start = 0;
            End = 0;
        }

        if (text.length() - Size == 1) {
            if (text.length() == 1)
                if(!text.at(0).isSpace())
                    Counter++;

            if (text.length() > 2) {
                Start = text.length() - 1;
                End = text.length();

                if (text.at(Start - 1).isSpace() && !text.at(End - 1).isSpace())
                    Counter++;
            }
        }

        else if (text.length() - Size > 1) {
            Counter = 0;
            if (!text.at(0).isSpace())
                Counter++;

            for (int i = 1; i < text.length(); i++)
                if(!text.at(i).isSpace() && text.at(i-1).isSpace())
                    Counter++;
        }

        Size = text.length();
        return Counter;
    }
}

QString TextEditor::CalculateSize() {
    float Length = toPlainText().length();
    QString UnitString;

    if  ((Length >= 0) & (Length < 1024))
        UnitString = " bytes";

    else if  ((Length > 1024) & (Length < 1048576)) {
        Length /= 1024;
        UnitString = " KB";
    }

    else if  ((Length > 1048576)) {
        Length /= 1048576;
        UnitString = " MB";
    }

    float RoundedLength = floorf(Length * 100 + 0.5) / 100;

    return QString::number(RoundedLength) + UnitString;
}

QString TextEditor::CheckMimeData(const QMimeData *Mime) {
    if(Mime->hasUrls()) {
        foreach (const QUrl & Url, Mime->urls()) {
            QString String = Url.toLocalFile();
            if (!String.isEmpty())
                return String;
        }
    }

    return QString();
}

void TextEditor::dragEnterEvent(QDragEnterEvent *Event) {
    if(!CheckMimeData(Event->mimeData()).isEmpty())
        Event->acceptProposedAction();
}

void TextEditor::dragMoveEvent(QDragMoveEvent *Event) {
    Event->acceptProposedAction();
}

void TextEditor::dropEvent(QDropEvent *Event) {
    QString File = CheckMimeData(Event->mimeData());

    if (!File.isEmpty())
        requestOpenDocumentFromDrop(File);
}

void TextEditor::ExportHTML() {
    QString FileLocation = QFileDialog::getSaveFileName(this, Shared::Export, QDir::homePath(), "*.html");
    qApp->setOverrideCursor(Qt::WaitCursor);

    if  (!FileLocation.isEmpty()) {
        QFile File(FileLocation);
        if (File.open(QIODevice::WriteOnly | QIODevice::Text)) {
            File.write(document()->toHtml().toUtf8());
            File.close();
        }

        else
            QMessageBox::warning(this, Shared::Error,
                                 Shared::CannotWriteFile.arg(FileLocation).arg(File.errorString()));
    }
    qApp->restoreOverrideCursor();
}

void TextEditor::ExportPDF() {
    QString FileLocation = QFileDialog::getSaveFileName(this, Shared::Export, QDir::homePath(), "*.pdf");
    qApp->setOverrideCursor(Qt::WaitCursor);

    if  (!FileLocation.isEmpty()) {
        QPrinter Printer(QPrinter::HighResolution);
        Printer.setOutputFormat(QPrinter::PdfFormat);
        Printer.setOutputFileName(FileLocation);
        Printer.setDocName(documentTitle());
        Printer.setFontEmbeddingEnabled(true);
        Printer.setCreator(Shared::GetUserName());

        document()->print(&Printer);
    }
    qApp->restoreOverrideCursor();
}

void TextEditor::keyPressEvent(QKeyEvent *e) {
    QString DocumentTitle = documentTitle();

    QTextCursor Cursor = textCursor();
    int Position = Cursor.position();

    if (e->key() == Qt::Key_ParenLeft) {
        Cursor.insertText(")");
        Cursor.setPosition(Position);
        setTextCursor(Cursor);
    }

    if (e->key() == Qt::Key_BracketLeft) {
        Cursor.insertText("]");
        Cursor.setPosition(Position);
        setTextCursor(Cursor);
    }

    if (e->key() == Qt::Key_BraceLeft) {
        Cursor.insertText("}");
        Cursor.setPosition(Position);
        setTextCursor(Cursor);
    }

    if (e->key() == Qt::Key_QuoteDbl) {
        Cursor.insertText("");
        Cursor.setPosition(Position);
        setTextCursor(Cursor);
    }

    if (e->key() == Qt::Key_Apostrophe) {
        Cursor.insertText("'");
        Cursor.setPosition(Position);
        setTextCursor(Cursor);
    }

    else
        QPlainTextEdit::keyPressEvent(e);

    setDocumentTitle(DocumentTitle);
}

void TextEditor::New() {
    requestNew();
}

void TextEditor::Open() {
    requestOpen();
}

void TextEditor::OpenFile(const QString FileLocation) {
    qApp->setOverrideCursor(Qt::WaitCursor);
    if  (!FileLocation.isEmpty()) {
        if (MaybeSave()) {
            QFile File(FileLocation);

            if (File.open(QFile::ReadOnly | QFile::WriteOnly | QFile::ReadWrite)) {
                QTextStream InputFile(&File);
                InputFile.setCodec("UTF-8");
                setPlainText(InputFile.readAll());
                File.close();
                Filename = FileLocation;
                SetupFile();

                qApp->restoreOverrideCursor();
                return;
            }

            QMessageBox::warning(this, Shared::Error,
                                 Shared::CannotReadFile.arg(FileLocation).arg(File.errorString()));

            qApp->restoreOverrideCursor();
            return;
        }
    }
    qApp->restoreOverrideCursor();
}

void TextEditor::Print() {
    qApp->setOverrideCursor(Qt::WaitCursor);
    QPrinter Printer(QPrinter::HighResolution);
    QPrintDialog *Dialog = new QPrintDialog(&Printer, this);

    Printer.setDocName(documentTitle());
    Printer.setFontEmbeddingEnabled(true);
    Printer.setCreator(Shared::GetUserName());

    if (Dialog->exec() == QDialog::Accepted)
        document()->print(&Printer);

    qApp->restoreOverrideCursor();
}

void TextEditor::SetupFile() {
    document()->setModified(false);
    HighlightByExtension();

    setDocumentTitle(QFileInfo(Filename).fileName());
    requestUpdateTitle();
}

void TextEditor::UpdateDocumentStatus() {
    QString LengthString    = Shared::Length + ": " + CalculateSize();
    QString LineCountString = Shared::Lines  + ": " + QString::number(document()->blockCount());
    QString WordCountString = Shared::Words  + ": " + QString::number(CountWords());

    DocumentStatus->setText(LengthString + "    " + WordCountString + "    " + LineCountString);
}

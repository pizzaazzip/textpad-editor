#ifndef TEXTEDITOR_HH
#define TEXTEDITOR_HH

#include "Code/TextEdit/SearchDialog/SearchDialog.hh"

class TextEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = 0);
    QString  Filename;
    int      documentNumber;

    int       Start;
    int       End;
    long long Size;
    long long Counter;

    // Extra widgets
    QLabel      *DocumentStatus;
    QWidget     *LineCountArea;
    FindDialog  *SearchDialog;

    // Public line count functions
    int  LineNumberAreaWidth();
    void LineNumberAreaPaintEvent(QPaintEvent *event);

public slots:
    // Saving functions
    bool MaybeSave();
    bool Save();
    bool SaveAs();
    bool SaveFile(const QString FileLocation);

    // Export functions
    void ExportHTML();
    void ExportPDF();

    // Syntax highlighter functions
    void HighlightByExtension();
    void Highlight_Current_Line();

    // File functions
    void New();
    void Open();
    void OpenFile(const QString FileLocation);
    void Print();
    void SetupFile();
    void UpdateDocumentStatus();

    // Line count functions
    void UpdateLineNumberArea(const QRect &, int);
    void UpdateLineNumberAreaWidth(int NewBlockCount);

    // Drag and drop functions
    QString CheckMimeData(const QMimeData *Mime);

    // Other functions
    int CountWords();
    QString CalculateSize();

signals:
    // Used to communicate with MainWindow
    void requestHighlightByExtension(short FileType);
    void requestUpdateTitle();
    void requestNew();
    void requestOpen();
    void requestOpenDocumentFromDrop(QString File);

protected:
    // Used for line count
    void resizeEvent(QResizeEvent *event);

    // Used for drag and drop
    void dragEnterEvent(QDragEnterEvent *Event);
    void dragMoveEvent(QDragMoveEvent *Event);
    void dropEvent(QDropEvent *Event);

    // Used for multiline identation
    void keyPressEvent(QKeyEvent *e);

};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(TextEditor *editor) : QWidget(editor)
    {
        TextEdit = editor;
    }

    QSize sizeHint() const
    {
        return QSize(TextEdit->LineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event)
    {
        TextEdit->LineNumberAreaPaintEvent(event);
    }

private:
    TextEditor *TextEdit;
};


#endif

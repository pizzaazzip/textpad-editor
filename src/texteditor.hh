#ifndef TEXTEDITOR_HH
#define TEXTEDITOR_HH

#include "src/objects.hh"
#include "src/searchdialog.hh"

QT_BEGIN_NAMESPACE

class TextEditor : public QPlainTextEdit {
    Q_OBJECT

public:
    TextEditor(QWidget *parent = 0);

    bool         HighlightLine;
    bool         LineCountEnabled;
    FindDialog  *SearchDialog;
    QColor       Background;
    QColor       Foreground;
    QColor       HighlightLineBackground;
    QLabel      *DocumentStatus;
    QString      FileName;
    QString      StyleString;
    QWidget     *LineCountArea;

    void LineNumberAreaPaintEvent(QPaintEvent *event);
    int LineNumberAreaWidth();

public slots:
    bool MaybeSave();
    bool Save();
    bool SaveAs();
    bool SaveFile(const QString FileLocation);
    void HighlightByExtension();
    void HighlightCurrentLine();
    void New();
    void Open();
    void OpenFile(const QString FileLocation);
    void Print();
    void SetupFile();
    void UpdateDocumentStatus();
    void UpdateLineNumberArea(const QRect &, int);
    void UpdateLineNumberAreaWidth(int NewBlockCount);

signals:
    void requestUpdateRecentFiles(bool Add, const QString FilePath);
    void requestHighlightByExtension(const char FileType);
    void requestUpdateTitle();

protected:
    void resizeEvent(QResizeEvent *event);
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(TextEditor *editor) : QWidget(editor) {
        TextEdit = editor;
    }

    QSize sizeHint() const {
        return QSize(TextEdit->LineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) {
        TextEdit->LineNumberAreaPaintEvent(event);
    }

private:
    TextEditor *TextEdit;
};

namespace textEditor {
class MainWindow: public TextEditor{};
}

QT_END_NAMESPACE

#endif

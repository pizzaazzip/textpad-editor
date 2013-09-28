#ifndef HIGHLIGHTER_HH
#define HIGHLIGHTER_HH

#include <QTextCharFormat>
#include <QSyntaxHighlighter>
#include <QMessageBox>

using namespace std;

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    int SelectedLanguage;

public slots:
    void setLanguage(int languageId);
    void setColor();

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat valueFormat;
    QTextCharFormat functionsFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat preprocessorFormat;
    QTextCharFormat otherFormat;

    HighlightingRule rule;

    QString QuotesString;
    QString SingleLineComment;
    QString CommentEndExpressionString;
    QString CommentStartExpressionString;
    QString FunctionsString;

    QStringList KeywordPatterns;
    QStringList OtherPatterns;
    QStringList BoolPatterns;
    QStringList ValuePatterns;

    QString NumbersString;

private slots:
    void setBash();
    void setC();
    void setCSS();
    void setHTML();
    void setJava();
    void setLaTeX();
    void setPython();
    void setVala();
    void setVB();
};

#endif

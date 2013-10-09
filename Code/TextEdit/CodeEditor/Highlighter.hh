#ifndef HIGHLIGHTER_HH
#define HIGHLIGHTER_HH

#include <QFile>
#include <QFileDialog>
#include <QStringList>
#include <QTextStream>
#include <QTextCharFormat>
#include <QSyntaxHighlighter>

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
    QRegExp ValueStartExpression;
    QRegExp ValueEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat functionsFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat numbersFormat;

    HighlightingRule rule;

    QString SingleLineComment;
    QString CommentEndExpressionString;
    QString CommentStartExpressionString;
    QString FunctionsString;

    QStringList KeywordPatterns;


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

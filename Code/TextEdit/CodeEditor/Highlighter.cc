// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/TextEditor.hh"
#include "Code/TextEdit/CodeEditor/Highlighter.hh"

Highlighter::Highlighter(QTextDocument *parent): QSyntaxHighlighter(parent) {
    NumbersString = "[0-9][0-9]*";
    QuotesString = "\".*\"|\'.*\'";

    setColor();
    setLanguage(1);
}

void Highlighter::highlightBlock(const QString &text) {
    if (SelectedLanguage != 1) {
        foreach (const HighlightingRule &rule, highlightingRules) {
            QRegExp expression(rule.pattern);
            int index = expression.indexIn(text);
            while (index >= 0) {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
            }
        }

        setCurrentBlockState(0);

        int startIndex = 0;
        if (previousBlockState() != 1)
            startIndex = commentStartExpression.indexIn(text);

        while (startIndex >= 0) {
            int endIndex = commentEndExpression.indexIn(text, startIndex);
            int commentLength;
            if (endIndex == -1) {
                setCurrentBlockState(1);
                commentLength = text.length() - startIndex;
            }

            else
                commentLength = endIndex - startIndex + commentEndExpression.matchedLength();

            setFormat(startIndex, commentLength, multiLineCommentFormat);
            startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
        }
    }
}

void Highlighter::setColor() {
    // Keywords, such as [this, if, case]
    keywordFormat.setForeground(Shared::Keywords);

    // Multiline comments
    multiLineCommentFormat.setForeground(Shared::Comments);

    // Functions
    functionsFormat.setForeground(Shared::Functions);

    // Booleans and [default]
    otherFormat.setForeground(Shared::OtherColor);

    // Numbers [0-9] and preprocessors
    preprocessorFormat.setForeground(Shared::Numbers);

    // Quotes [""]
    quotationFormat.setForeground(Shared::Quotations);

    // Single line comments
    singleLineCommentFormat.setForeground(Shared::Comments);

    // Variables, such as [int, float, double]
    valueFormat.setForeground(Shared::Quotations);

    valueFormat.setFontWeight(QFont::Bold);
    otherFormat.setFontWeight(QFont::Bold);
    keywordFormat.setFontWeight(QFont::Bold);
}

void Highlighter::setLanguage(int languageId) {
    highlightingRules.clear();

    switch (languageId) {
    case 1:  languageId = 1; break;
    case 2:  setBash();      break;
    case 3:  setC();         break;
    case 4:  setCSS();       break;
    case 5:  setHTML();      break;
    case 6:  setJava();      break;
    case 7:  setLaTeX();     break;
    case 8:  setPython();    break;
    case 9:  setVala();      break;
    case 10: setVB();        break;
    default: languageId = 1; break;
    }

    SelectedLanguage = languageId;

    if (languageId != 1) {

        // Keyword format
        foreach (const QString &pattern, KeywordPatterns) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

        // Boolean format
        foreach (const QString &pattern, BoolPatterns) {
            rule.pattern = QRegExp(pattern);
            rule.format = otherFormat;
            highlightingRules.append(rule);
        }

        // Class format
        foreach (const QString &pattern, ValuePatterns) {
            rule.pattern = QRegExp(pattern);
            rule.format = valueFormat;
            highlightingRules.append(rule);
        }

        // Prepocessor format
        foreach (const QString &pattern, OtherPatterns) {
            rule.pattern = QRegExp(pattern);
            rule.format = preprocessorFormat;
            highlightingRules.append(rule);
        }

        // Functions Format
        rule.pattern = QRegExp(FunctionsString);
        rule.format = functionsFormat;
        highlightingRules.append(rule);

        // Quotes format
        rule.pattern = QRegExp(QuotesString);
        rule.format = quotationFormat;
        highlightingRules.append(rule);

        // Single-line comment format
        rule.pattern = QRegExp(SingleLineComment);
        rule.format = singleLineCommentFormat;
        highlightingRules.append(rule);

        // Multiline comment
        commentStartExpression = QRegExp(CommentStartExpressionString);
        commentEndExpression = QRegExp(CommentEndExpressionString);
    }

    // Update the highlighter
    rehighlight();
}

void TextEditor::HighlightByExtension() {
    // Figure the extension of the file
    QFile File(Filename);
    QString FileSuffix = QFileInfo(File).suffix();
    short FileType;

    if  (!FileSuffix.isEmpty()) {
        if      (FileSuffix == "txt"  ) FileType = 1;
        else if (FileSuffix == "sh"   ) FileType = 2;
        else if (FileSuffix == "css"  ) FileType = 4;
        else if (FileSuffix == "java" ) FileType = 6;
        else if (FileSuffix == "tex"  ) FileType = 8;
        else if (FileSuffix == "vala" ) FileType = 9;
        else if (FileSuffix == "vb"   ) FileType = 10;

        else if  ((FileSuffix == "cc" ) | (FileSuffix == "c")    | (FileSuffix == "cpp") |
                 (FileSuffix == "cxx")  | (FileSuffix == "h")    | (FileSuffix == "hh")  |
                 (FileSuffix == "hxx")  | (FileSuffix == "m")    | (FileSuffix == "mm")  |
                 (FileSuffix == "xib")  | (FileSuffix == "cs")   | (FileSuffix == "h++") |
                 (FileSuffix == "c++"))  FileType = 3;
        else if  ((FileSuffix == "htm") | (FileSuffix == "html") |
                 (FileSuffix == "xml"))  FileType = 5;

        else if  ((FileSuffix == "py")  | (FileSuffix == "pyw") | (FileSuffix == "pyc")  |
                 (FileSuffix == "pyo")  | (FileSuffix == "pyd") )  FileType = 7;
        else FileType = 1;
    }

    else
        FileType = 1;

    requestHighlightByExtension(FileType);
}

void TextEditor::Highlight_Current_Line() {
    QList<QTextEdit::ExtraSelection> ExtraSelections;
    QTextEdit::ExtraSelection Selection;

    Selection.format.setBackground(Shared::HighlightLineBackground);
    Selection.format.setProperty(QTextFormat::FullWidthSelection, true);

    Selection.cursor = textCursor();
    Selection.cursor.clearSelection();

    if (Shared::Highlight_Current_Line)
        ExtraSelections.append(Selection);
    else
        ExtraSelections.clear();

    setExtraSelections(ExtraSelections);
}

// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/TextEditor.hh"
#include "Code/TextEdit/CodeEditor/Highlighter.hh"

Highlighter::Highlighter(QTextDocument *parent): QSyntaxHighlighter(parent) {
    setColor();
    setLanguage(1);
}

void Highlighter::highlightBlock(const QString &text) {
    if (SelectedLanguage != 1) {
        foreach (const HighlightingRule &rule, highlightingRules) {
            QRegExp expression (rule.pattern);
            int index = 0;
            index = text.indexOf(expression);
            while (index >= 0) {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = text.indexOf(expression, index + length);
            }
        }

        // Handle the comments
        setCurrentBlockState(0);
        int startIndex = 0;

        if (commentStartExpression.isEmpty() || commentEndExpression.isEmpty())
            return;

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

    // Numbers [0-9]
    numbersFormat.setForeground(Shared::Numbers);

    // Quotations [""]
    quotationFormat.setForeground(Shared::Quotations);

    // Single line comments
    singleLineCommentFormat.setForeground(Shared::Comments);

    functionsFormat.setFontItalic(true);
    keywordFormat.setFontWeight(QFont::Bold);

    setLanguage(SelectedLanguage);
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

        // Number format
        rule.pattern = QRegExp("[0-9][0-9]*");
        rule.format = numbersFormat;
        highlightingRules.append(rule);

        // Functions Format
        rule.pattern = QRegExp(FunctionsString);
        rule.format = functionsFormat;
        highlightingRules.append(rule);

        // The fucking quotations
        rule.pattern = QRegExp("\"[^\"]+\"");
        rule.format = quotationFormat;
        highlightingRules.append(rule);

        // Blank qoutations
        rule.pattern = QRegExp("\"\"");
        rule.format = quotationFormat;
        highlightingRules.append(rule);

        // Chars
        rule.pattern = QRegExp("'[^\']+'");
        rule.format = quotationFormat;
        highlightingRules.append(rule);

        // Blank chars
        rule.pattern = QRegExp("''");
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
        // Text files
        if      (FileSuffix == "txt"  ) FileType = 1;

        // Bash script
        else if (FileSuffix == "sh"   ) FileType = 2;

        // C/C#/C++/Objective-C files
        else if  ((FileSuffix == "cc" )  | (FileSuffix == "c")    | (FileSuffix == "cpp") |
                  (FileSuffix == "cxx")  | (FileSuffix == "h")    | (FileSuffix == "hh")  |
                  (FileSuffix == "hxx")  | (FileSuffix == "m")    | (FileSuffix == "mm")  |
                  (FileSuffix == "xib")  | (FileSuffix == "cs")   | (FileSuffix == "h++") |
                  (FileSuffix == "c++"))  FileType = 3;

        // CSS files
        else if (FileSuffix == "css"  ) FileType = 4;

        // HTML files
        else if  ((FileSuffix == "htm")  | (FileSuffix == "html") |
                  (FileSuffix == "xml"))  FileType = 5;

        // Java files
        else if  ((FileSuffix == "java") | (FileSuffix == "class") |
                  (FileSuffix == "jar"))  FileType = 6;

        // Python files
        else if  ((FileSuffix == "py")   | (FileSuffix == "pyw") | (FileSuffix == "pyc")  |
                  (FileSuffix == "pyo")  | (FileSuffix == "pyd") )  FileType = 7;

        // LaTeX files
        else if (FileSuffix == "tex"  ) FileType = 8;

        // Vala files
        else if (FileSuffix == "vala" ) FileType = 9;

        // Visual basic files
        else if  ((FileSuffix == "vb")   | (FileSuffix == "vbe") | (FileSuffix == "vbs")  |
                  (FileSuffix == "bas"))  FileType = 10;

        // Other files
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
// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setCSS() {
    // There are no booleans in CSS?
    BoolPatterns << "\\";

    // Comments
    CommentEndExpressionString = "\\*/";
    CommentStartExpressionString = "/\\*";
    SingleLineComment = "\\";

    // There are no functions in CSS?
    FunctionsString = "\\";

    // Numbers
    OtherPatterns << NumbersString;

    // Keywords
    KeywordPatterns << " ([^<]*):" << "a: ([^<]*)";

    // This variable has no use...
    ValuePatterns << "\\";

    // Remind me that I should work on supporting this language
    QMessageBox Message;
    Message.setText("<b>This language is not fully supported!</b>");
    Message.setInformativeText("Many keywords and features of this language may not appear correctly highlighted.");
    Message.setIcon(QMessageBox::Warning);
    Message.exec();
}

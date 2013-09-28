// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setHTML() {
    // There are no boolean in HTML
    BoolPatterns << "\\";

    // Comments
    CommentEndExpressionString = "\\-->";
    CommentStartExpressionString = "<\\!\\-\\-";
    SingleLineComment = "<!--[^\n]*-->";

    // Functions (shit)
    FunctionsString = "\\b[A-Za-z0-9_]+ (?=\\ ()";

    // Keywords
    KeywordPatterns << "\\b?html\\b" << "\\b?xml\\b" << "/>" <<  ">" << "<";

    // Numbers
    OtherPatterns << NumbersString;

    // Tags, such as <bullshit>Privacy exists</bullshit>
    ValuePatterns << "\\b[A-Za-z0-9_]+(?=[/>])" << "\\b[A-Za-z0-9_]+(?=\\=)" << "\"(?=[></])";

    // Remind me that I should work on supporting this language
    QMessageBox Message;
    Message.setText("<b>This language is not fully supported!</b>");
    Message.setInformativeText("Many keywords and features of this language may not appear correctly highlighted.");
    Message.setIcon(QMessageBox::Warning);
    Message.exec();
}

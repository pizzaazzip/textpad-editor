// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setPython() {
    // Booleans
    BoolPatterns    << "\\btrue\\b"    << "\\bfalse\\b";

    // Keywords
    KeywordPatterns << "\\band\\b"     << "\\bdel\\b"    << "\\bfrom\\b"
                    << "\\bnot\\b"     << "\\bwhile\\b"  << "\\bas\\b"
                    << "\\belif\\b"    << "\\bglobal\\b" << "\\bor\\b"
                    << "\\bwith\\b"    << "\\bassert\\b" << "\\belse\\b"
                    << "\\bif\\b"      << "\\bpass\\b"   << "\\byield\\b"
                    << "\\bbreak\\b"   << "\\bexcept\\b" << "\\bimport\\b"
                    << "\\bprint\\b"   << "\\bclass\\b"  << "\\bexec\\b"
                    << "\\bin\\b"      << "\\braise\\b"  << "\\bcontinue\\b"
                    << "\\bfinally\\b" << "\\bis\\b"     << "\\rbeturn\\b"
                    << "\\bdef\\b"     << "\\bfor\\b"    << "\\blambda\\b"
                    << "\\btry\\b"     << "\\bself\\b";

    // There are no multiline comments in Python
    CommentEndExpressionString = "\\";
    CommentStartExpressionString = "\\";

    // Functions
    FunctionsString = "\\b[A-Za-z0-9_]+ (?=\\ ()";

    // Comments
    SingleLineComment = "#[^\n]*";

    // Numbers
    OtherPatterns << NumbersString;

    // This variable should be deleted by 0.9
    ValuePatterns << "\\";

    // Remind me that I should work on supporting this language
    QMessageBox Message;
    Message.setText("<b>This language is not fully supported!</b>");
    Message.setInformativeText("Many keywords and features of this language may not appear correctly highlighted.");
    Message.setIcon(QMessageBox::Warning);
    Message.exec();
}

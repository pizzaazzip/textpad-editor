// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setVB() {
    // Booleans
    BoolPatterns    << "\\btrue\\b"     << "\\bfalse\\b";

    // Keywords
    KeywordPatterns << "\\bauto\\b"     << "\\bsigned\\b"   << "\\bwhile\\b"
                    << "\\bstruct\\b"   << "\\bbreak\\b"    << "\\belse\\b"
                    << "\\bswitch\\b"   << "\\bcase\\b"     << "\\benum\\b"
                    << "\\bregister\\b" << "\\btypedef\\b"  << "\\bextern\\b"
                    << "\\breturn\\b"   << "\\bunion\\b"    << "\\bcontinue\\b"
                    << "\\bfor\\b"      << "\\bauto\\b"     << "\\bstatic\\b"
                    << "\\bgoto\\b"     << "\\bunsigned\\b" << "\\bif\\b"
                    << "\\bsizeof\\b"   << "\\bvolatile\\b" << "\\bdo\\b"
                    << "\\bthis\\b"     << "\\bvoid\\b";

    // Multiline comments
    CommentEndExpressionString = "\\*/";
    CommentStartExpressionString = "/\\*";

    // Functions, such as main()
    FunctionsString = "\\b[A-Za-z0-9_]+ (?=\\ ()";

    // Single line comment (like the one you are now reading)
    SingleLineComment = "//[^\n]*";

    // Other random shit
    OtherPatterns << "\\busing\\b"          << "\\bnamespace\\b"
                  << "[#include]+ (?=\\ ()" << NumbersString;

    // Things that declare any type of variable
    ValuePatterns << "\\bdouble\\b" << "\\bbool\\b"        << "\\bint\\b"
                  << "\\blong\\b"   << "\\bshort\\b"       << "\\bchar\\b"
                  << "\\bconst\\b"  << "\\blong double\\b" << "\\bfloat\\b";

    // Remind me that I should work on supporting this language
    QMessageBox Message;
    Message.setText("<b>This language is not fully supported!</b>");
    Message.setInformativeText("Many keywords and features of this language may not appear correctly highlighted.");
    Message.setIcon(QMessageBox::Warning);
    Message.exec();
}

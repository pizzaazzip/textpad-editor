// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setBash() {
    // Booleans
    BoolPatterns    << "\\btrue\\b" << "\\bfalse\\b";

    // Keywords
    KeywordPatterns << "\\bsudo\\b" << "\\bthen\\b"  << "\\bcd\\b"    << "\\bif\\b"
                    << "\\bfi\\b"   << "\\bwhile\\b" << "\\bwait\\b"  << "\\bexit\\b" 
                    << "\\bfor\\b"  << "\\bdo\\b";

    // Random shit
    ValuePatterns   << "\\";

    // Numbers
    OtherPatterns   << NumbersString;

    // There are no multiline comments in bash
    CommentEndExpressionString   = "\\";
    CommentStartExpressionString = "\\";

    // Functions
    FunctionsString              = "\\b[A-Za-z0-9_]+ (?=\\ ()";

    // Comments
    SingleLineComment            = "#[^\n]*";
}

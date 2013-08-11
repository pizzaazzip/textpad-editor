// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/highlighter.hh"

void Highlighter::setBash()
{
    BoolPatterns << "\\";
    KeywordPatterns << "\\bsudo\\b" << "\\bthen\\b" << "\\bcd\\b"    << "\\bif\\b"
                    << "\\bfi\\b"   << "\\btrue\\b" << "\\bfalse\\b" << "\\bwhile\\b"
                    << "\\bwait\\b" << "\\bexit\\b" << "\\bfor\\b"   << "\\bdo\\b";
    CommentEndExpressionString = "\\";
    CommentStartExpressionString = "\\";
    FunctionsString = "\\b[A-Za-z0-9_]+(?=\\()";
    SingleLineComment = "#[^\n]*";
    OtherPatterns << NumbersString;
    ValuePatterns << "\\";
}

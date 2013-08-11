// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/highlighter.hh"

void Highlighter::setCSS()
{
    BoolPatterns << "\\";
    CommentEndExpressionString = "\\*/";
    CommentStartExpressionString = "/\\*";
    FunctionsString = "\\b[A-Za-z0-9_]+(?=\\()";
    OtherPatterns << NumbersString;
    SingleLineComment = "\\";
    KeywordPatterns << "([^<]*):" << "a:([^<]*)";
    ValuePatterns << "\\";
}

// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/highlighter.hh"

void Highlighter::setPython()
{
    BoolPatterns << "\\";
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
                    << "\\btry\\b";
    CommentEndExpressionString = "\\";
    CommentStartExpressionString = "\\";
    FunctionsString = "\\b[A-Za-z0-9_]+(?=\\()";
    SingleLineComment = "#[^\n]*";
    OtherPatterns << NumbersString;
    ValuePatterns << "\\";
}

// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/highlighter.hh"

void Highlighter::setC()
{
    BoolPatterns    << "\\btrue\\b"     << "\\bfalse\\b"    << "\\bdefault\\b";
    KeywordPatterns << "\\bauto\\b"     << "\\bsigned\\b"   << "\\bwhile\\b"
                    << "\\bstruct\\b"   << "\\bbreak\\b"    << "\\belse\\b"
                    << "\\bswitch\\b"   << "\\bcase\\b"     << "\\benum\\b"
                    << "\\bregister\\b" << "\\btypedef\\b"  << "\\bextern\\b"
                    << "\\breturn\\b"   << "\\bunion\\b"    << "\\bcontinue\\b"
                    << "\\bfor\\b"      << "\\bauto\\b"     << "\\bstatic\\b"
                    << "\\bgoto\\b"     << "\\bunsigned\\b" << "\\bif\\b"
                    << "\\bsizeof\\b"   << "\\bvolatile\\b" << "\\bdo\\b"
                    <<	"\\bthis\\b"    << "\\bvoid\\b";
    CommentEndExpressionString = "\\*/";
    CommentStartExpressionString = "/\\*";
    FunctionsString = "\\b[A-Za-z0-9_]+(?=\\()";
    SingleLineComment = "//[^\n]*";
    OtherPatterns << "#([^<]*)" << "\\busing\\b" << "\\bnamespace\\b"
                  << NumbersString;
    ValuePatterns << "\\bdouble\\b" << "\\bbool\\b"        << "\\bint\\b"
                  << "\\blong\\b"   << "\\bshort\\b"       << "\\bchar\\b"
                  << "\\bconst\\b"  << "\\blong double\\b" << "\\bfloat\\b";
}

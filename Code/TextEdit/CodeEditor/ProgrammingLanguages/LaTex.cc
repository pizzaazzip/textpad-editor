// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setLaTeX() {
    // Keywords
    KeywordPatterns << "\\\\section"           << "\\\\item"              << "\\\\subsection" << "\\\\subsubsection"
                    << "\\\\chapter"           << "\\\\begin"             << "\\\\end"        << "\\\\usepackage" <<"\\\\document"
                    << "\\\\cite"              << "\\\\upcite"            << "\\\\ref"        << "\\\\label"      <<"\\\\caption"
                    << "\\\\hline"             << "\\\\cline"             << "\\\\toprule"    << "\\\\bottomrule" <<"\\\\\\\\"
                    << "\\{flalign\\}"         << "\\&"                   << "\\\\;"
                    << "\\{subarray\\}"        << "\\{equation\\}"        << "\\{cases\\}"    << "\\{array\\}"
                    << "\\\\bibliographystyle" << "\\\\title"             << "\\\\footnote"   << "\\\\includegraphics"
                    << "\\\\centering"         << "\\\\vspace"            << "\\\\scriptsize"
                    << "\\\\bibitem"           << "\\{thebibliography\\}" << "\\{abstract\\}";

    // Comments
    CommentEndExpressionString = "\\";
    CommentStartExpressionString = "\\";
    FunctionsString = "\\b[A-Za-z0-9_]+ (?=\\ ()";
    SingleLineComment = "\%[^\n]*";
}

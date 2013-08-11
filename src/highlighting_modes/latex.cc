// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/highlighter.hh"

void Highlighter::setLaTeX()
{
    BoolPatterns << "\\";
    KeywordPatterns << "\\\\section"           << "\\\\item"              << "\\\\subsection" << "\\\\subsubsection"
                    << "\\\\chapter"           << "\\\\begin"             << "\\\\end"        << "\\\\usepackage" <<"\\\\document"
                    << "\\\\cite"              << "\\\\upcite"            << "\\\\ref"        << "\\\\label"      <<"\\\\caption"
                    << "\\\\hline"             << "\\\\cline"             << "\\\\toprule"    << "\\\\bottomrule" <<"\\\\\\\\"
                    << "\\{flalign\\}"         << "\\&"                   << "\\\\;"
                    << "\\{subarray\\}"        << "\\{equation\\}"        << "\\{cases\\}"    << "\\{array\\}"
                    << "\\\\bibliographystyle" << "\\\\title"             << "\\\\footnote"   << "\\\\includegraphics"
                    << "\\\\centering"         << "\\\\vspace"            << "\\\\scriptsize"
                    << "\\\\bibitem"           << "\\{thebibliography\\}" << "\\{abstract\\}";
    CommentEndExpressionString = "\\";
    CommentStartExpressionString = "\\";
    FunctionsString = "\\b[A-Za-z0-9_]+(?=\\()";
    SingleLineComment = "\%[^\n]*";
    OtherPatterns << "\\\\alpha"      << "\\\\beta"     << "\\\\gamma"    << "\\\\delta"    << "\\\\epsilon" << "\\\\zeta" << "\\\\eta"
                  << "\\\\theta"      << "\\\\iota"     << "\\\\kappa"    << "\\\\lambda"   << "\\\\mu"      << "\\\\xi"   << "\\\\nu"
                  << "\\\\rho"        << "\\\\sigma"    << "\\\\tau"      << "\\\\upsilon"  << "\\\\phi"     << "\\\\chi"  <<"\\\\pi"
                  << "\\\\psi"        << "\\\\omega"    << "\\\\varGamma" << "\\\\varSigma" << "\\\\varTheta"
                  << "\\\\varLambda"  << "\\\\varkappa" << "\\\\varpi"    << "\\\\varsigma"
                  << "\\\\varepsilon" << "\\\\varOmega" << "\\\\emptyset" << "\\\\square"   << NumbersString;
    ValuePatterns << "\\";
}
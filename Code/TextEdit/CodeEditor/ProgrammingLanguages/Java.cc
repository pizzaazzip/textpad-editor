// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/TextEdit/CodeEditor/Highlighter.hh"

void Highlighter::setJava() {
    // Keywords
    {
        KeywordPatterns.clear();

        // Load the file that contains all the keywords of this language
        QFile File(":/Syntax/Code/TextEdit/CodeEditor/Syntax/Keywords/Java");
        File.open(QIODevice::ReadOnly);
        QTextStream TextStream(&File);

        // Read each line of the file and append it to the KeywordPatterns list
        while (!TextStream.atEnd()) {
            QString Line = "\\b";
            Line.append(TextStream.readLine());
            Line.append("\\b");
            KeywordPatterns.append(Line);
        }

        File.close();
    }

    // Multiline comments
    CommentEndExpressionString = "\\*/";
    CommentStartExpressionString = "/\\*";

    // Functions
    FunctionsString = "\\b[A-Za-z0-9_]+ (?=\\ ()\\b";

    // Single line comment (like the one you are now reading)
    SingleLineComment = "//[^\n]*";
}

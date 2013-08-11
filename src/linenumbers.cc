// This file uses code from the CodeEditor example, which is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
// Please read the "AUTHORS" file for more information.

#include "src/texteditor.hh"

int TextEditor::LineNumberAreaWidth()
{
    if (LineCountEnabled) {
        int Digits = 1;
        int Max = qMax(1, blockCount());
        while (Max >= 10) {
            Max /= 10;
            ++Digits;
        }

        return 16 + fontMetrics().width(QLatin1Char('9')) * Digits;
    }
    return 0;
}

void TextEditor::LineNumberAreaPaintEvent(QPaintEvent *event)
{
    Background.setRgb(240, 240, 240);
    Foreground.setRgb(140, 140, 140);

    QPainter painter(LineCountArea);
    painter.fillRect(event->rect(), Background);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString Number = QString::number(blockNumber + 1);
            painter.setPen(Foreground);
            painter.drawText(0, top, LineCountArea->width(), fontMetrics().height(),
                             Qt::AlignCenter, Number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

void TextEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    LineCountArea->setGeometry(QRect(cr.left(), cr.top(), LineNumberAreaWidth(), cr.height()));
}


void TextEditor::UpdateLineNumberAreaWidth(int) {
    setViewportMargins(LineNumberAreaWidth(), 0, 0, 0);
}

void TextEditor::UpdateLineNumberArea(const QRect &rect, int dy) {
    if (dy)
        LineCountArea->scroll(0, dy);
    else
        LineCountArea->update(0, rect.y(), LineCountArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        UpdateLineNumberAreaWidth(0);
}

#ifndef COLORSCHEMES_HH
#define COLORSCHEMES_HH

#include "src/objects.hh"

class ColorSchemes : public QObject {
    Q_OBJECT

public:
    ColorSchemes(QWidget *parent = 0);

    QColor Background;
    QColor Comments;
    QColor Foreground;
    QColor Functions;
    QColor HighlightLineBackground;
    QColor HighlightLineForeground;
    QColor Keywords;
    QColor Numbers;
    QColor OtherColor;
    QColor Qoutations;
    QColor SelectedBackground;
    QColor SelectedForeground;

public slots:
    void SetColorscheme(int Colorscheme);
};

#endif

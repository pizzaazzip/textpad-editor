// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/colorschemes.hh"

ColorSchemes::ColorSchemes(QWidget *parent): QObject(parent) {}

void ColorSchemes::SetColorscheme(int Colorscheme) {
    switch (Colorscheme) {
    case 1:
        // Default
        Background.setRgb              (254, 254, 254);
        Comments.setRgb                ( 29, 112,   0);
        Foreground.setRgb              ( 41,  40,  39);
        Functions.setRgb               ( 38,   0, 114);
        HighlightLineBackground.setRgb (232, 242, 254);
        Keywords.setRgb                (108,   0,   0);
        Numbers.setRgb                 ( 38,   0, 114);
        OtherColor.setRgb              (109, 109, 109);
        Qoutations.setRgb              (192,  94,   0);
        SelectedBackground.setRgb      (210, 220, 248);
        SelectedForeground.setRgb      ( 41,  40,  39);
        break;
    case 2:
        // Cobalt
        Background.setRgb              (  0,  27,  51);
        Comments.setRgb                (  0, 136, 255);
        Foreground.setRgb              (255, 255, 255);
        Functions.setRgb               (255, 157,   6);
        HighlightLineBackground.setRgb (  0,  59, 112);
        Keywords.setRgb                (255, 157,   6);
        Numbers.setRgb                 (255,   0,  68);
        OtherColor.setRgb              (255,   0,  68);
        Qoutations.setRgb              ( 58, 217,   0);
        SelectedBackground.setRgb      (  0, 136, 255);
        SelectedForeground.setRgb      (255, 255, 255);
        break;
    case 3:
        // Kate
        Background.setRgb              (255, 255, 255);
        Comments.setRgb                (128, 128, 128);
        Foreground.setRgb              (  0,   0,   0);
        Functions.setRgb               (  0,  87, 174);
        HighlightLineBackground.setRgb (238, 246, 255);
        Keywords.setRgb                (  0,  87, 174);
        Numbers.setRgb                 (176, 126,   0);
        OtherColor.setRgb              (  0,  87, 174);
        Qoutations.setRgb              (221,   0,   0);
        SelectedBackground.setRgb      ( 67, 172, 232);
        SelectedForeground.setRgb      (255, 255, 255);
        break;
    case 4:
        // Oblivion
        Background.setRgb              ( 46,  52,  54);
        Comments.setRgb                (136, 138, 133);
        Foreground.setRgb              (211, 215, 207);
        Functions.setRgb               (206,  92,   0);
        HighlightLineBackground.setRgb ( 85,  87,  83);
        Keywords.setRgb                (138, 226,  52);
        Numbers.setRgb                 (237, 212,   0);
        OtherColor.setRgb              (206,  92,   0);
        Qoutations.setRgb              (237, 212,   0);
        SelectedBackground.setRgb      (136, 138, 133);
        SelectedForeground.setRgb      (238, 238, 236);
        break;
    case 5:
        // Tango
        Background.setRgb              (255, 255, 255);
        Comments.setRgb                ( 32,  74, 135);
        Foreground.setRgb              (109, 109, 111);
        Functions.setRgb               (164,   0,   0);
        HighlightLineBackground.setRgb (238, 238, 236);
        Keywords.setRgb                (164,   0,   0);
        Numbers.setRgb                 (173, 127, 168);
        OtherColor.setRgb              ( 78, 154,   6);
        Qoutations.setRgb              (173, 127, 168);
        SelectedBackground.setRgb      ( 67, 172, 232);
        SelectedForeground.setRgb      (255, 255, 255);
        break;
    }
}

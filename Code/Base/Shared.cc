// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/Base/Shared.hh"

/// Initialize all variables used for settings
bool Shared::Statusbar_Enabled      = false;
bool Shared::Toolbar_Enabled        = false;
bool Shared::WordWrap_Enabled       = false;
bool Shared::Highlight_Current_Line = false;
bool Shared::Line_Count             = false;
bool Shared::Syntax_Highlighting    = false;

char        Shared::Selected_Colorscheme = 0;
int         Shared::Document_Number = 1;
int         Shared::Window_Number   = 1;
QFont       Shared::Font;
QString     Shared::Language;
QStringList Shared::Recent_Files;

/// Initialize QColors used for colorschemes
QColor Shared::Background               ;
QColor Shared::Comments                 ;
QColor Shared::Foreground               ;
QColor Shared::Functions                ;
QColor Shared::HighlightLineBackground  ;
QColor Shared::HighlightLineForeground  ;
QColor Shared::Keywords                 ;
QColor Shared::Numbers                  ;
QColor Shared::OtherColor               ;
QColor Shared::Quotations               ;
QColor Shared::SelectedTextBackground   ;
QColor Shared::SelectedTextForeground   ;
QColor Shared::LineCountBackgroundColor ;
QColor Shared::LineCountForegroundColor ;

QString Shared::CheckOS()
{
    // Get the current operating system
#ifdef Q_OS_MAC
    return "Mac";
#endif
#ifdef Q_OS_LINUX
    return "Linux";
#endif
#ifdef Q_OS_WIN32
    return "Windows";
#endif
}

QString Shared::GetUserName() {
    // Get the current user name
    if (CheckOS() == "Windows")
        return getenv("USERNAME");
    else
        return getenv("USER");
}

void Shared::SetColorschemes(char Selected_Colorscheme) {
    switch (Selected_Colorscheme)
    {
    case 1:
        // Default
        Background.setRgb               (254, 254, 254);
        Comments.setRgb                 ( 29, 112,   0);
        Foreground.setRgb               ( 41,  40,  39);
        Functions.setRgb                ( 38,   0, 114);
        HighlightLineBackground.setRgb  (232, 242, 254);
        Keywords.setRgb                 (108,   0,   0);
        Numbers.setRgb                  ( 38,   0, 114);
        OtherColor.setRgb               (109, 109, 109);
        Quotations.setRgb               (192,  94,   0);
        SelectedTextBackground.setRgb   (210, 220, 248);
        SelectedTextForeground.setRgb   ( 41,  40,  39);
        LineCountBackgroundColor.setRgb (240, 240, 240);
        LineCountForegroundColor.setRgb (140, 140, 140);
        break;
    case 2:
        // Cobalt
        Background.setRgb               (  0,  27,  51);
        Comments.setRgb                 (  0, 136, 255);
        Foreground.setRgb               (255, 255, 255);
        Functions.setRgb                (255, 157,   6);
        HighlightLineBackground.setRgb  (  0,  59, 112);
        Keywords.setRgb                 (255, 157,   6);
        Numbers.setRgb                  (255,   0,  68);
        OtherColor.setRgb               (255,   0,  68);
        Quotations.setRgb               ( 58, 217,   0);
        SelectedTextBackground.setRgb   (  0, 136, 255);
        SelectedTextForeground.setRgb   (255, 255, 255);
        LineCountBackgroundColor.setRgb (  0,  20,  44);
        LineCountForegroundColor.setRgb (  0, 101, 191);
        break;
    case 3:
        // Grayscale
        Background.setRgb               (255, 255, 255);
        Comments.setRgb                 (150, 150, 150);
        Foreground.setRgb               ( 45,  45,  45);
        Functions.setRgb                ( 45,  45,  45);
        HighlightLineBackground.setRgb  (232, 232, 232);
        Keywords.setRgb                 ( 45,  45,  45);
        Numbers.setRgb                  (145, 145, 145);
        OtherColor.setRgb               (145, 145, 145);
        Quotations.setRgb               (145, 145, 145);
        SelectedTextBackground.setRgb   (210, 210, 210);
        SelectedTextForeground.setRgb   ( 45,  45,  45);
        LineCountBackgroundColor.setRgb (245, 245, 245);
        LineCountForegroundColor.setRgb (140, 140, 140);
        break;
    case 4:
        // Kate
        Background.setRgb               (255, 255, 255);
        Comments.setRgb                 (128, 128, 128);
        Foreground.setRgb               (  0,   0,   0);
        Functions.setRgb                (  0,  87, 174);
        HighlightLineBackground.setRgb  (238, 246, 255);
        Keywords.setRgb                 (  0,  87, 174);
        Numbers.setRgb                  (176, 126,   0);
        OtherColor.setRgb               (  0,  87, 174);
        Quotations.setRgb               (221,   0,   0);
        SelectedTextBackground.setRgb   ( 67, 172, 232);
        SelectedTextForeground.setRgb   (255, 255, 255);
        LineCountBackgroundColor.setRgb (235, 235, 235);
        LineCountForegroundColor.setRgb (105, 105, 105);
        break;
    case 5:
        // Oblivion
        Background.setRgb               ( 46,  52,  54);
        Comments.setRgb                 (136, 138, 133);
        Foreground.setRgb               (211, 215, 207);
        Functions.setRgb                (206,  92,   0);
        HighlightLineBackground.setRgb  ( 85,  87,  83);
        Keywords.setRgb                 (138, 226,  52);
        Numbers.setRgb                  (237, 212,   0);
        OtherColor.setRgb               (206,  92,   0);
        Quotations.setRgb               (237, 212,   0);
        SelectedTextBackground.setRgb   (136, 138, 133);
        SelectedTextForeground.setRgb   (238, 238, 236);
        LineCountBackgroundColor.setRgb ( 40,  42,  44);
        LineCountForegroundColor.setRgb (111, 115, 107);
        break;
    case 6:
        // Tango
        Background.setRgb               (255, 255, 255);
        Comments.setRgb                 ( 32,  74, 135);
        Foreground.setRgb               (109, 109, 111);
        Functions.setRgb                (164,   0,   0);
        HighlightLineBackground.setRgb  (238, 238, 236);
        Keywords.setRgb                 (164,   0,   0);
        Numbers.setRgb                  (173, 127, 168);
        OtherColor.setRgb               ( 78, 154,   6);
        Quotations.setRgb               (173, 127, 168);
        SelectedTextBackground.setRgb   ( 67, 172, 232);
        SelectedTextForeground.setRgb   (255, 255, 255);
        LineCountBackgroundColor.setRgb (240, 240, 240);
        LineCountForegroundColor.setRgb (140, 140, 140);
        break;
    }
}

void Shared::ReadSettings() {
    QSettings Settings("Textpad Editor", "Settings");

    int FontSize;
    QString FontName;

    if (CheckOS() == "Mac") {
        FontSize = 11;
        FontName = "Menlo";
    }
    else {
        FontSize = 10;
        FontName = "Courier";
    }

    Font.setFamily    (Settings.value("Font.Family",    FontName).toString());
    Font.setPointSize (Settings.value("Font.Size",      FontSize).toInt());
    Font.setBold      (Settings.value("Font.Bold",      false).toBool());
    Font.setItalic    (Settings.value("Font.Italic",    false).toBool());
    Font.setUnderline (Settings.value("Font.Underline", false).toBool());
    Font.setStrikeOut (Settings.value("Font.Strikeout", false).toBool());

    // Load other settings
    Selected_Colorscheme   = Settings.value("Selected_Colorscheme",    1     ).toInt();
    Highlight_Current_Line = Settings.value("Highlight_Current_Line",  true  ).toBool();
    Language               = Settings.value("Language",                "en"  ).toString();
    Line_Count             = Settings.value("Line_Count",              false ).toBool();
    Statusbar_Enabled      = Settings.value("Statusbar_Enabled",       true  ).toBool();
    Toolbar_Enabled        = Settings.value("Toolbar_Enabled",         true  ).toBool();
    WordWrap_Enabled       = Settings.value("WordWrap_Enabled",        true  ).toBool();
    Recent_Files           = Settings.value("Recent_Files").toStringList();

    // Set the language
    TranslateStrings();
}

void Shared:: WriteSettings(QMainWindow *Window) {
    QSettings Settings("Textpad Editor", "Settings");

    // Window Settings
    Settings.setValue("Window.Geometry",  Window->geometry());

    // Font settings
    Settings.setValue("Font.Family",    Font.family());
    Settings.setValue("Font.Size",      Font.pointSize());
    Settings.setValue("Font.Bold",      Font.bold());
    Settings.setValue("Font.Italic",    Font.italic());
    Settings.setValue("Font.Underline", Font.underline());
    Settings.setValue("Font.Strikeout", Font.strikeOut());

    // Other settings
    Settings.setValue("Selected_Colorscheme",   Selected_Colorscheme);
    Settings.setValue("Highlight_Current_Line", Highlight_Current_Line);
    Settings.setValue("Language",               Language);
    Settings.setValue("Line_Count",             Line_Count);
    Settings.setValue("Statusbar_Enabled",      Statusbar_Enabled);
    Settings.setValue("Recent_Files",           Recent_Files);
    Settings.setValue("Toolbar_Enabled",        Toolbar_Enabled);
    Settings.setValue("WordWrap_Enabled",       WordWrap_Enabled);
}

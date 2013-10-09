// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/Base/Shared.hh"

/// Initialize all strings

// File menu
QString Shared::File;
QString Shared::New;
QString Shared::Open;
QString Shared::Save;
QString Shared::SaveAs;
QString Shared::Print;
QString Shared::Close;
QString Shared::Quit;

// Recent files menu
QString Shared::OpenRecent;
QString Shared::ClearAction;

// Export Menu
QString Shared::Export;
QString Shared::ExportHTML;
QString Shared::ExportPDF;

// Edit menu
QString Shared::Edit;
QString Shared::Undo;
QString Shared::Redo;
QString Shared::Cut;
QString Shared::Copy;
QString Shared::Paste;
QString Shared::SelectAll;
QString Shared::SetReadOnly;
QString Shared::Find;
QString Shared::FindAndReplace;

// Format menu
QString Shared::Format;
QString Shared::SelectFont;
QString Shared::WordWrap;

// View menu
QString Shared::View;
QString Shared::Advanced;
QString Shared::ToggleToolbar;
QString Shared::ToggleStatusbar;
QString Shared::Fullscreen;
QString Shared::HighlightLine;
QString Shared::LineCount;

// Language menu
QString Shared::LanguageMenu;
QString Shared::English;
QString Shared::French;
QString Shared::German;
QString Shared::Romanian;
QString Shared::Russian;
QString Shared::Spanish;

// Modes menu
QString Shared::Modes;
QString Shared::NormalMode;
QString Shared::MinimalMode;
QString Shared::CustomMode;

// Color schemes menu
QString Shared::ColorSchemes;
QString Shared::DefaultColorscheme;
QString Shared::CobaltColorscheme;
QString Shared::GrayscaleColorscheme;
QString Shared::KateColorscheme;
QString Shared::OblivionColorscheme;
QString Shared::TangoColorscheme;

// Highlight Mode menu
QString Shared::HighlightMode;
QString Shared::PlainText;
QString Shared::BashScript;
QString Shared::C;
QString Shared::CSS;
QString Shared::HTML;
QString Shared::Java;
QString Shared::LaTeX;
QString Shared::Python;
QString Shared::Vala;
QString Shared::VBasic;

// Help menu
QString Shared::Help;
QString Shared::Contents;
QString Shared::AboutTextpad;
QString Shared::ReportBug;
QString Shared::AboutQt;
QString Shared::License;
QString Shared::Website;
QString Shared::Donation;

// Other strings
QString Shared::Untitled;
QString Shared::Words;
QString Shared::Length;
QString Shared::Lines;
QString Shared::SaveChangesToDocument;
QString Shared::YourChangesWillBeLost;
QString Shared::AreYouSure;
QString Shared::YouErasedAllContent;
QString Shared::Error;
QString Shared::CannotWriteFile;
QString Shared::CannotReadFile;
QString Shared::HelpText;
QString Shared::RestartApp;

// Search and Replace dialog strings
QString Shared::Search;
QString Shared::Replace;
QString Shared::ReplaceAll;
QString Shared::FindWhat;
QString Shared::ReplaceWith;
QString Shared::CloseDialog;
QString Shared::MatchCase;
QString Shared::Warning;
QString Shared::NoMatchesFound;
QString Shared::SearchAndReplace;
QString Shared::WholeWords;

void Shared::TranslateStrings()
{
    /// Translate all strings

    // File menu
    File   = "&" + QObject::tr("File");
    New    = QObject::tr("New");
    Open   = QObject::tr("Open") + "...";
    Save   = QObject::tr("Save");
    SaveAs = QObject::tr("Save as") + "...";
    Print  = QObject::tr("Print") + "...";
    Close  = QObject::tr("Close this document");
    Quit   = QObject::tr("Quit");

    // Recent files menu
    OpenRecent  = QObject::tr("Open recent") + "...";
    ClearAction = QObject::tr("Clear recent files");

    // Export Menu
    Export     = QObject::tr("Export");
    ExportHTML = QObject::tr("HTML");
    ExportPDF  = QObject::tr("PDF");

    // Edit menu
    Edit           = "&" + QObject::tr("Edit");
    Undo           = QObject::tr("Undo");
    Redo           = QObject::tr("Redo");
    Cut            = QObject::tr("Cut");
    Copy           = QObject::tr("Copy");
    Paste          = QObject::tr("Paste");
    SelectAll      = QObject::tr("Select all");
    SetReadOnly    = QObject::tr("Set read only");
    Find           = QObject::tr("Find");
    FindAndReplace = QObject::tr("Find and replace");

    // Format menu
    Format     = "&" + QObject::tr("Format");
    SelectFont = QObject::tr("Fonts") + "...";
    WordWrap   = QObject::tr("Word wrap");

    // View menu
    View            = "&" + QObject::tr("View");
    Advanced        = QObject::tr("Advanced");
    ToggleToolbar   = QObject::tr("Toolbar");
    ToggleStatusbar = QObject::tr("Statusbar");
    Fullscreen      = QObject::tr("Fullscreen");
    HighlightLine   = QObject::tr("Highlight current line");
    LineCount       = QObject::tr("Line numbers");

    // Languages menu
    LanguageMenu = QObject::tr("Languages");
    //French       = "Français (French)";
    //German       = "Deutsch (German)";
    //Romanian     = "Română (Romanian)";
    //Russian      = "Русский (Russian)";
    //Spanish      = "Español (Spanish)";
    English  = "English";
    French   = "French";
    German   = "German";
    Romanian = "Romanian";
    Russian  = "Russian";
    Spanish  = "Spanish";

    // Modes menu
    Modes       = QObject::tr("Modes");
    NormalMode  = QObject::tr("Normal mode");
    MinimalMode = QObject::tr("Minimal mode");
    CustomMode  = QObject::tr("Custom mode");

    // Color schemes menu
    ColorSchemes         = QObject::tr("Color schemes");
    DefaultColorscheme   = QObject::tr("Default");
    CobaltColorscheme    = "Cobalt";
    GrayscaleColorscheme = "Grayscale";
    KateColorscheme      = "Kate";
    OblivionColorscheme  = "Oblivion";
    TangoColorscheme     = "Tango";

    // Highlight Mode menu
    HighlightMode = QObject::tr("Highlighting mode");
    PlainText     = QObject::tr("Plain text");
    BashScript    = "Bash";
    C             = "C/C++";
    CSS           = "CSS";
    HTML          = "HTML";
    Java          = "Java";
    LaTeX         = "LaTeX";
    Python        = "Python";
    Vala          = "Vala";
    VBasic        = "Visual Basic";

    // Help menu
    Help         = QObject::tr("Help");
    Contents     = QObject::tr("View help") + "...";
    AboutTextpad = QObject::tr("About Textpad");
    ReportBug    = QObject::tr("Report bug") + "...";
    AboutQt      = QObject::tr("About Qt") + "...";
    License      = QObject::tr("License") + "...";
    Website      = QObject::tr("Website") + "...";
    Donation     = QObject::tr("Make a donation") + "...";

    // Other strings
    Untitled              = QObject::tr("Untitled") + " ";
    Words                 = QObject::tr("Words");
    Length                = QObject::tr("Length");
    Lines                 = QObject::tr("Lines");
    SaveChangesToDocument = "<b>" + QObject::tr("Do you want to save the changes made to document '%1'?") + "</b>";
    YourChangesWillBeLost = QObject::tr("Your changes will be lost if you don't save them.");
    AreYouSure            = "<b>" + QObject::tr("Are you sure you want to do this?") + "</b>";
    YouErasedAllContent   = QObject::tr("You have erased all content on this document, saving it could be fatal!");
    Error                 = QObject::tr("Error");
    CannotWriteFile       = QObject::tr("Cannot write file") + " %1:\n%2";
    CannotReadFile        = QObject::tr("Cannot read file")  + " %1:\n%2";
    RestartApp            = QObject::tr("The language change will take effect after a restart of Textpad.");
    HelpText              = QObject::tr("<p><h2>To use Textpad, you need to be able to:</h2></p><hr>"
                                        "<ul>"
                                        "<li>Use a mouse and/or trackpad.</li>"
                                        "<li>To read and understand a text.</li>"
                                        "<li>Know how to use a keyboard.</li>"
                                        "<li>Use common sense.</li>"
                                        "<li>Pay attention when saving files "
                                        "(don't blame me for not knowing where you put your files).</li>"
                                        "<li>Click the <i>Report bug</i> menu if you find a bug, "
                                        "this will help me make Textpad better and more stable.</li>"
                                        "</ul>"
                                        "<hr>"
                                        "<p><b>That's all!</b></p>"
                                        "<p>If you are willing to write a manual with all the features of Textpad, "
                                        "please do it and <a href = 'mailto:alex_sr97@outlook.com'>send it to my email</a> "
                                        "(please provide your name or nickname so that I can give credit for your work).</p>");
    // Search dialog strings
    Search           = QObject::tr("Search");
    Replace          = QObject::tr("Replace");
    ReplaceAll       = QObject::tr("Replace all");
    FindWhat         = QObject::tr("Find what:");
    ReplaceWith      = QObject::tr("Replace with:");
    CloseDialog      = QObject::tr("Close");
    MatchCase        = QObject::tr("Match case");
    Warning          = QObject::tr("Warning");
    NoMatchesFound   = QObject::tr("No matches found");
    SearchAndReplace = QObject::tr("Search and Replace (%1 Matches)");
    WholeWords       = QObject::tr("Whole words only");
}

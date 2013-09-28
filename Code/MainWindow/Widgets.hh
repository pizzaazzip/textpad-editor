#ifndef QWIDGETS_HH
#define QWIDGETS_HH

#include "Code/TextEdit/TextEditor.hh"
#include "Code/TextEdit/CodeEditor/Highlighter.hh"

QT_BEGIN_NAMESPACE

class Widgets
{
public:
    /// Toolbars
    QToolBar *Toolbar;

    /// Searching features
    QLineEdit *FindLineEdit;
    QAction   *ControlLineEdit;
    QAction   *Spacer2Action;

    /// File menu
    QMenu   *File;
    QAction *New;
    QAction *Open;
    QAction *Save;
    QAction *SaveAs;
    QAction *Print;
    QAction *Close;
    QAction *Quit;

    /// Recent files menu
    QMenu   *RecentFiles;
    enum {Max_Recent_Files = 10};
    QAction *RecentFilesAction[Max_Recent_Files];
    QAction *SeparatorAction;
    QAction *ClearAction;

    /// Export Menu
    QMenu *Export;
    QAction *ExportHTML;
    QAction *ExportPDF;

    /// Edit menu
    QMenu   *Edit;
    QAction *Undo;
    QAction *Redo;
    QAction *Cut;
    QAction *Copy;
    QAction *Paste;
    QAction *SelectAll;
    QAction *SetReadOnly;
    QAction *Find;
    QAction *FindAndReplace;

    /// Format menu
    QMenu   *Format;
    QAction *SelectFont;
    QAction *WordWrap;

    /// View menu
    QMenu   *View;
    QMenu   *Advanced;
    QAction *ToggleToolbar;
    QAction *ToggleStatusbar;
    QAction *Fullscreen;
    QAction *HighlightLine;
    QAction *LineCount;
    QAction *ExtraSeparatorAction;

    /// Languages menu
    QMenu   *Languages;
    QAction *French;
    QAction *German;
    QAction *Romanian;
    QAction *Russian;
    QAction *Spanish;
    QAction *English;

    /// Modes menu
    QMenu   *Modes;
    QAction *NormalMode;
    QAction *MinimalMode;
    QAction *CustomMode;

    /// Color schemes menu
    QMenu   *ColorSchemes;
    QAction *DefaultColorscheme;
    QAction *CobaltColorscheme;
    QAction *GrayscaleColorscheme;
    QAction *KateColorscheme;
    QAction *OblivionColorscheme;
    QAction *TangoColorscheme;

    /// Highlight Mode menu
    QMenu   *HighlightMode;
    QAction *PlainText;
    QAction *BashScript;
    QAction *C;
    QAction *CSS;
    QAction *HTML;
    QAction *Java;
    QAction *LaTeX;
    QAction *Python;
    QAction *Vala;
    QAction *VBasic;

    /// Help menu
    QMenu   *Help;
    QAction *Contents;
    QAction *AboutTextpad;
    QAction *ReportBug;
    QAction *AboutQt;
    QAction *License;
    QAction *Website;
    QAction *Donation;

    /// Signal mappers
    QSignalMapper *ColorSignalMapper;
    QSignalMapper *HighlightSignalMapper;

    QWidget randomWidget;

public slots:
    void CreateActions(QMainWindow *Window)
    {
        QString IconPath = ":/Icons/Resources/Icons/24x24/";
        AboutQt         = new QAction(QIcon(),                                    Shared::AboutQt,         Window);
        AboutTextpad    = new QAction(QIcon()                      ,              Shared::AboutTextpad,    Window);
        Close           = new QAction(QIcon(IconPath + "Close.png"),              Shared::Close,           Window);
        Quit            = new QAction(QIcon(IconPath + "Quit.png"),               Shared::Quit,            Window);
        ClearAction     = new QAction(QIcon(),                                    Shared::ClearAction,     Window);
        Copy            = new QAction(QIcon(IconPath + "Copy.png"),               Shared::Copy,            Window);
        CustomMode      = new QAction(QIcon(),                                    Shared::CustomMode,      Window);
        Cut             = new QAction(QIcon(IconPath + "Cut.png"),                Shared::Cut,             Window);
        Donation        = new QAction(QIcon(),                                    Shared::Donation,        Window);
        ExportHTML      = new QAction(QIcon(),                                    Shared::ExportHTML,      Window);
        ExportPDF       = new QAction(QIcon(),                                    Shared::ExportPDF,       Window);
        Find            = new QAction(QIcon(IconPath + "Search.png"),             Shared::Find,            Window);
        FindAndReplace  = new QAction(QIcon(IconPath + "Search and Replace.png"), Shared::FindAndReplace,  Window);
        SelectFont      = new QAction(QIcon(),                                    Shared::SelectFont,      Window);
        Fullscreen      = new QAction(QIcon(IconPath + "Fullscreen.png"),         Shared::Fullscreen,      Window);
        HighlightLine   = new QAction(QIcon(),                                    Shared::HighlightLine,   Window);
        License         = new QAction(QIcon(),                                    Shared::License,         Window);
        LineCount       = new QAction(QIcon(),                                    Shared::LineCount,       Window);
        MinimalMode     = new QAction(QIcon(),                                    Shared::MinimalMode,     Window);
        New             = new QAction(QIcon(IconPath + "New.png"),                Shared::New,             Window);
        NormalMode      = new QAction(QIcon(),                                    Shared::NormalMode,      Window);
        Open            = new QAction(QIcon(IconPath + "Open.png"),               Shared::Open,            Window);
        Paste           = new QAction(QIcon(IconPath + "Paste.png"),              Shared::Paste,           Window);
        Print           = new QAction(QIcon(IconPath + "Print.png"),              Shared::Print,           Window);
        Redo            = new QAction(QIcon(IconPath + "Redo.png"),               Shared::Redo,            Window);
        Save            = new QAction(QIcon(IconPath + "Save.png"),               Shared::Save,            Window);
        SaveAs          = new QAction(QIcon(IconPath + "Save As.png"),            Shared::SaveAs,          Window);
        SelectAll       = new QAction(QIcon(IconPath + "Select All.png"),         Shared::SelectAll,       Window);
        SetReadOnly     = new QAction(QIcon(IconPath + "Lock.png"),               Shared::SetReadOnly,     Window);
        ToggleStatusbar = new QAction(QIcon(),                                    Shared::ToggleStatusbar, Window);
        ToggleToolbar   = new QAction(QIcon(),                                    Shared::ToggleToolbar,   Window);
        Undo            = new QAction(QIcon(IconPath + "Undo.png"),               Shared::Undo,            Window);
        Contents        = new QAction(QIcon(),                                    Shared::Contents,        Window);
        WordWrap        = new QAction(QIcon(),                                    Shared::WordWrap,        Window);
        ReportBug       = new QAction(QIcon(),                                    Shared::ReportBug,       Window);
        Website         = new QAction(QIcon(),                                    Shared::Website,         Window);

        DefaultColorscheme   = new QAction(Shared::DefaultColorscheme,   Window);
        CobaltColorscheme    = new QAction(Shared::CobaltColorscheme,    Window);
        GrayscaleColorscheme = new QAction(Shared::GrayscaleColorscheme, Window);
        KateColorscheme      = new QAction(Shared::KateColorscheme,      Window);
        OblivionColorscheme  = new QAction(Shared::OblivionColorscheme,  Window);
        TangoColorscheme     = new QAction(Shared::TangoColorscheme,     Window);

        PlainText  = new QAction(Shared::PlainText,  Window);
        BashScript = new QAction(Shared::BashScript, Window);
        C          = new QAction(Shared::C,          Window);
        CSS        = new QAction(Shared::CSS,        Window);
        HTML       = new QAction(Shared::HTML,       Window);
        Java       = new QAction(Shared::Java,       Window);
        LaTeX      = new QAction(Shared::LaTeX,      Window);
        Python     = new QAction(Shared::Python,     Window);
        Vala       = new QAction(Shared::Vala,       Window);
        VBasic     = new QAction(Shared::VBasic,     Window);

        English  = new QAction(Shared::English,  Window);
        French   = new QAction(Shared::French,   Window);
        German   = new QAction(Shared::German,   Window);
        Romanian = new QAction(Shared::Romanian, Window);
        Russian  = new QAction(Shared::Russian,  Window);
        Spanish  = new QAction(Shared::Spanish,  Window);

        SeparatorAction      = new QAction(Window);
        ExtraSeparatorAction = new QAction(Window);
        SeparatorAction->setSeparator      (true);
        ExtraSeparatorAction->setSeparator (true);

        DefaultColorscheme->setCheckable   (true);
        CobaltColorscheme->setCheckable    (true);
        GrayscaleColorscheme->setCheckable (true);
        KateColorscheme->setCheckable      (true);
        OblivionColorscheme->setCheckable  (true);
        TangoColorscheme->setCheckable     (true);

        PlainText->setCheckable  (true);
        BashScript->setCheckable (true);
        C->setCheckable          (true);
        CSS->setCheckable        (true);
        HTML->setCheckable       (true);
        Java->setCheckable       (true);
        LaTeX->setCheckable      (true);
        Python->setCheckable     (true);
        Vala->setCheckable       (true);
        VBasic->setCheckable     (true);

        English->setCheckable     (true);
        French->setCheckable      (true);
        German->setCheckable      (true);
        Romanian->setCheckable    (true);
        Russian->setCheckable     (true);
        Spanish->setCheckable     (true);

        CustomMode->setCheckable      (true);
        HighlightLine->setCheckable   (true);
        LineCount->setCheckable       (true);
        MinimalMode->setCheckable     (true);
        NormalMode->setCheckable      (true);
        SetReadOnly->setCheckable     (true);
        Find->setCheckable            (true);
        Fullscreen->setCheckable      (true);
        ToggleStatusbar->setCheckable (true);
        ToggleToolbar->setCheckable   (true);
        WordWrap->setCheckable        (true);

        CustomMode->setEnabled        (false);

        QActionGroup *ModesGroup = new QActionGroup(Window);
        ModesGroup->addAction(NormalMode);
        ModesGroup->addAction(MinimalMode);
        ModesGroup->addAction(CustomMode);

        QActionGroup *HighlightGroup = new QActionGroup(Window);
        HighlightGroup->addAction(PlainText);
        HighlightGroup->addAction(BashScript);
        HighlightGroup->addAction(C);
        HighlightGroup->addAction(CSS);
        HighlightGroup->addAction(HTML);
        HighlightGroup->addAction(Java);
        HighlightGroup->addAction(LaTeX);
        HighlightGroup->addAction(Python);
        HighlightGroup->addAction(Vala);
        HighlightGroup->addAction(VBasic);

        QActionGroup *LanguagesGroup = new QActionGroup(Window);
        LanguagesGroup->addAction(English);
        LanguagesGroup->addAction(French);
        LanguagesGroup->addAction(German);
        LanguagesGroup->addAction(Romanian);
        LanguagesGroup->addAction(Russian);
        LanguagesGroup->addAction(Spanish);

        HighlightSignalMapper = new QSignalMapper(Window);
        QObject::connect(PlainText,  SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(BashScript, SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(C,          SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(CSS,        SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(HTML,       SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(Java,       SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(LaTeX,      SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(Python,     SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(Vala,       SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));
        QObject::connect(VBasic,     SIGNAL(triggered()), HighlightSignalMapper, SLOT(map()));

        HighlightSignalMapper->setMapping(PlainText,  1);
        HighlightSignalMapper->setMapping(BashScript, 2);
        HighlightSignalMapper->setMapping(C,          3);
        HighlightSignalMapper->setMapping(CSS,        4);
        HighlightSignalMapper->setMapping(HTML,       5);
        HighlightSignalMapper->setMapping(Java,       6);
        HighlightSignalMapper->setMapping(LaTeX,      7);
        HighlightSignalMapper->setMapping(Python,     8);
        HighlightSignalMapper->setMapping(Vala,       9);
        HighlightSignalMapper->setMapping(VBasic,    10);

        QActionGroup *ColorschemesGroup = new QActionGroup(Window);
        ColorschemesGroup->addAction(DefaultColorscheme);
        ColorschemesGroup->addAction(CobaltColorscheme);
        ColorschemesGroup->addAction(GrayscaleColorscheme);
        ColorschemesGroup->addAction(KateColorscheme);
        ColorschemesGroup->addAction(OblivionColorscheme);
        ColorschemesGroup->addAction(TangoColorscheme);

        ColorSignalMapper = new QSignalMapper(Window);
        QObject::connect(DefaultColorscheme,   SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(CobaltColorscheme,    SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(GrayscaleColorscheme, SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(KateColorscheme,      SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(OblivionColorscheme,  SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(TangoColorscheme,     SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));

        ColorSignalMapper->setMapping(DefaultColorscheme,   1);
        ColorSignalMapper->setMapping(CobaltColorscheme,    2);
        ColorSignalMapper->setMapping(GrayscaleColorscheme, 3);
        ColorSignalMapper->setMapping(KateColorscheme,      4);
        ColorSignalMapper->setMapping(OblivionColorscheme,  5);
        ColorSignalMapper->setMapping(TangoColorscheme,     6);

        Close->setShortcut           (QKeySequence::Close);
        Quit->setShortcut            (QKeySequence::Quit);
        New->setShortcut             (QKeySequence::New);
        Open->setShortcut            (QKeySequence::Open);
        Save->setShortcut            (QKeySequence::Save);
        SaveAs->setShortcut          (QKeySequence::SaveAs);
        Print->setShortcut           (QKeySequence::Print);
        Undo->setShortcut            (QKeySequence::Undo);
        Redo->setShortcut            (QKeySequence::Redo);
        Cut->setShortcut             (QKeySequence::Cut);
        Copy->setShortcut            (QKeySequence::Copy);
        Paste->setShortcut           (QKeySequence::Paste);
        Find->setShortcut            (QKeySequence::Find);
        SelectAll->setShortcut       (QKeySequence::SelectAll);

        MinimalMode->setShortcut     (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_M));
        NormalMode->setShortcut      (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_N));
        ToggleStatusbar->setShortcut (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_S));
        ToggleToolbar->setShortcut   (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_T));
        WordWrap->setShortcut        (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_W));
        FindAndReplace->setShortcut  (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_F));
        Fullscreen->setShortcut      (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_F11));
        HighlightLine->setShortcut   (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_H));
        LineCount->setShortcut       (QKeySequence(Qt::ALT  + Qt::CTRL + Qt::Key_L));
        SelectFont->setShortcut      (QKeySequence(Qt::ALT  + Qt::Key_T));
        SetReadOnly->setShortcut     (QKeySequence(Qt::CTRL + Qt::Key_R));

        // List the About Qt action in the help menu (in Mac OS X)
        AboutQt->setMenuRole(QAction::NoRole);
        AboutTextpad->setMenuRole(QAction::AboutRole);
        Quit->setMenuRole(QAction::QuitRole);

        // Set some important aspects of the languages menu
        English->setObjectName  ("en-menu");
        French->setObjectName   ("fr-menu");
        German->setObjectName   ("de-menu");
        Romanian->setObjectName ("ro-menu");
        Russian->setObjectName  ("ru-menu");
        Spanish->setObjectName  ("es-menu");
    }

    void CreateMenubar(QMainWindow *Window)
    {
        AboutTextpad->setIconVisibleInMenu   (false);
        Close->setIconVisibleInMenu          (false);
        Quit->setIconVisibleInMenu           (false);
        Copy->setIconVisibleInMenu           (false);
        Cut->setIconVisibleInMenu            (false);
        Find->setIconVisibleInMenu           (false);
        FindAndReplace->setIconVisibleInMenu (false);
        SelectFont->setIconVisibleInMenu     (false);
        Fullscreen->setIconVisibleInMenu     (false);
        New->setIconVisibleInMenu            (false);
        Open->setIconVisibleInMenu           (false);
        Paste->setIconVisibleInMenu          (false);
        Print->setIconVisibleInMenu          (false);
        Redo->setIconVisibleInMenu           (false);
        Save->setIconVisibleInMenu           (false);
        SaveAs->setIconVisibleInMenu         (false);
        SelectAll->setIconVisibleInMenu      (false);
        SetReadOnly->setIconVisibleInMenu    (false);
        Undo->setIconVisibleInMenu           (false);
        Contents->setIconVisibleInMenu       (false);
        ReportBug->setIconVisibleInMenu      (false);

        File   = Window->menuBar()->addMenu(Shared::File);
        Edit   = Window->menuBar()->addMenu(Shared::Edit);
        Format = Window->menuBar()->addMenu(Shared::Format);
        View   = Window->menuBar()->addMenu(Shared::View);
        Help   = Window->menuBar()->addMenu(Shared::Help);

        // Setup the file menu
        File->addAction(New);
        File->addAction(Open);

        // Setup the recent files menu
        RecentFiles = File->addMenu(Shared::OpenRecent);
        for (int i = 0; i < Max_Recent_Files; ++i)
            RecentFiles->addAction(RecentFilesAction[i]);
        RecentFiles->addAction(SeparatorAction);
        RecentFiles->addAction(ClearAction);

        File->addSeparator();
        File->addAction(Save);
        File->addAction(SaveAs);
        File->addSeparator();

        // Setup the export menu
        Export = File->addMenu(Shared::Export);
        Export->addAction(ExportHTML);
        Export->addAction(ExportPDF);

        File->addSeparator();
        File->addAction(Print);
        File->addSeparator();
        File->addAction(Close);
        File->addAction(Quit);

        // Setup the Edit menu
        Edit->addAction(Undo);
        Edit->addAction(Redo);
        Edit->addSeparator();
        Edit->addAction(Cut);
        Edit->addAction(Copy);
        Edit->addAction(Paste);
        Edit->addSeparator();
        Edit->addAction(SelectAll);
        Edit->addSeparator();
        Edit->addAction(Find);
        Edit->addAction(FindAndReplace);
        Edit->addSeparator();
        Edit->addAction(SetReadOnly);

        // Setup the Format menu
        Format->addAction(SelectFont);
        Format->addSeparator();
        Format->addAction(WordWrap);

        // Setup the View menu
        View->addAction(ToggleToolbar);
        View->addAction(ToggleStatusbar);

        View->addSeparator();
        Modes = View->addMenu(Shared::Modes);
        Modes->addAction(NormalMode);
        Modes->addAction(MinimalMode);
        Modes->addSeparator();
        Modes->addAction(CustomMode);

        Advanced = View->addMenu(Shared::Advanced);
        Advanced->addAction(HighlightLine);
        Advanced->addAction(LineCount);
        Advanced->addSeparator();

        ColorSchemes = Advanced->addMenu(Shared::ColorSchemes);
        ColorSchemes->addAction(DefaultColorscheme);
        ColorSchemes->addSeparator();
        ColorSchemes->addAction(CobaltColorscheme);
        ColorSchemes->addAction(GrayscaleColorscheme);
        ColorSchemes->addAction(KateColorscheme);
        ColorSchemes->addAction(OblivionColorscheme);
        ColorSchemes->addAction(TangoColorscheme);

        HighlightMode = Advanced->addMenu(Shared::HighlightMode);
        HighlightMode->addAction(PlainText);
        HighlightMode->addSeparator();
        HighlightMode->addAction(BashScript);
        HighlightMode->addAction(C);
        HighlightMode->addAction(CSS);
        HighlightMode->addAction(HTML);
        HighlightMode->addAction(Java);
        HighlightMode->addAction(LaTeX);
        HighlightMode->addAction(Python);
        HighlightMode->addAction(Vala);
        HighlightMode->addAction(VBasic);

        View->addSeparator();
        Languages = View->addMenu(Shared::LanguageMenu);
        Languages->addAction(English);
        Languages->addAction(French);
        Languages->addAction(German);
        Languages->addAction(Romanian);
        Languages->addAction(Russian);
        Languages->addAction(Spanish);

        if (Shared::CheckOS() != "Mac")
        {
            View->addSeparator();
            View->addAction(Fullscreen);
        }

        // Help menu
        Help->addAction(AboutQt);
        Help->addAction(AboutTextpad);
        Help->addSeparator();
        Help->addAction(License);
        Help->addAction(Contents);
        Help->addAction(ReportBug);
        Help->addSeparator();
        Help->addAction(Donation);
        Help->addSeparator();
        Help->addAction(Website);
    }

    void CreateToolbar(QMainWindow *Window)
    {
        // Create the Toolbars
        Toolbar = Window->addToolBar("Toolbar");
        Toolbar->setMovable(false);

        // Add some actions to the toolbar
        Toolbar->addAction(New);
        Toolbar->addAction(Open);
        Toolbar->addAction(Save);
        Toolbar->addSeparator();
        Toolbar->addAction(Print);
        Toolbar->addSeparator();
        Toolbar->addAction(Undo);
        Toolbar->addAction(Redo);
        Toolbar->addSeparator();
        Toolbar->addAction(Cut);
        Toolbar->addAction(Copy);
        Toolbar->addAction(Paste);
        Toolbar->addSeparator();
        Toolbar->addAction(Find);
        Toolbar->addAction(FindAndReplace);

        // Set the spacer size between the window border and the QFindLineEdit
        short Spacer2_VSpacing = 6;
        if (Shared::CheckOS() == "Mac")
            Spacer2_VSpacing = 0;

        QWidget *Spacer_1 = new QWidget();
        QWidget *Spacer_2 = new QWidget();
        Spacer_1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        Spacer_2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        Spacer_2->setMinimumSize(Spacer2_VSpacing, 0);
        Toolbar->addWidget(Spacer_1);

        if (Shared::CheckOS() == "Mac")
        {
            Toolbar->setMinimumHeight(32);
            Toolbar->setMaximumHeight(32);
            Window->setUnifiedTitleAndToolBarOnMac(true);
        }

        FindLineEdit = new QLineEdit(Window);
        FindLineEdit->setMinimumWidth(175);
        FindLineEdit->setMaximumWidth(175);

        // Get the color of the border of the FindLineEdit
        QImage Image = QImage(FindLineEdit->size(),
                              QImage::Format_ARGB32_Premultiplied);
        QFrame Frame;
        Frame.setFrameShape(QFrame::StyledPanel);
        Frame.render(&Image);
        QColor BorderColor = QColor(Image.pixel(0, 0));

        if (BorderColor.rgb() == FindLineEdit->palette().background().color().rgb())
            BorderColor.setNamedColor("#bebebe");

        FindLineEdit->setFrame(false);
        FindLineEdit->setStyleSheet("QLineEdit { background-image: url(':/Icons/Resources/Icons/16x16/Search.png');"
                                    "background-repeat: no-repeat;"
                                    "background-position: left;"
                                    "padding-left: 22px;"
                                    "border: 1.2px solid " + BorderColor.name() + "; }");
        FindLineEdit->setPlaceholderText(Shared::Search);

        ControlLineEdit = Toolbar->addWidget(FindLineEdit);
        Spacer2Action = Toolbar->addWidget(Spacer_2);
        Toolbar->removeAction(ControlLineEdit);
        Toolbar->removeAction(Spacer2Action);
    }

    void SetupUI(QMainWindow *Window)
    {
        CreateActions(Window);
        CreateMenubar(Window);
        CreateToolbar(Window);
    }
};

namespace _widgets
{
class MainWindow: public Widgets {};
}

QT_END_NAMESPACE

#endif

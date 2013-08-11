#ifndef UI_HH
#define UI_HH

#include "src/objects.hh"

QT_BEGIN_NAMESPACE

class ui {
public:
    // Toolbar
    QToolBar *Toolbar;

    // File menu
    QMenu   *File;
    QMenu   *RecentFiles;
    QAction *New;
    QAction *Open;
    QAction *Save;
    QAction *SaveAs;
    QAction *Print;
    QAction *Quit;

    // Edit menu
    QMenu   *Edit;
    QAction *Undo;
    QAction *Redo;
    QAction *Cut;
    QAction *Copy;
    QAction *Paste;
    QAction *SelectAll;
    QAction *SetReadOnly;
    QAction *FindAndReplace;
    QAction *SetReadOnlySeparator;

    // Format menu
    QMenu   *Format;
    QAction *SelectFont;
    QAction *WordWrap;

    // View menu
    QMenu   *View;
    QMenu   *Advanced;
    QAction *ToggleToolbar;
    QAction *ToggleStatusbar;
    QAction *Fullscreen;
    QAction *FullscreenSeparator;
    QAction *HighlightLine;
    QAction *LineCount;

    // Modes menu
    QMenu   *Modes;
    QAction *NormalMode;
    QAction *MinimalMode;
    QAction *CustomMode;

    // Color schemes menu
    QMenu   *Colorschemes;
    QAction *DefaultColorscheme;
    QAction *CobaltColorscheme;
    QAction *KateColorscheme;
    QAction *OblivionColorscheme;
    QAction *TangoColorscheme;

    // Highlight Mode menu
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

    // Help menu
    QMenu   *Help;
    QAction *Contents;
    QAction *AboutTextpad;
    QAction *ReportBug;
    QAction *AboutQt;
    QAction *License;
    QAction *Website;
    QAction *Donation;

    // Signal mappers
    QSignalMapper *ColorSignalMapper;
    QSignalMapper *HighlightSignalMapper;

public slots:
    void CreateActions(QMainWindow *Window) {
        QString IconPath = ":/icons/24x24/";
        AboutQt         = new QAction(QIcon(),                             QObject::tr("About Qt"),               Window);
        AboutTextpad    = new QAction(QIcon()                      ,       QObject::tr("About Textpad"),          Window);
        Copy            = new QAction(QIcon(IconPath + "copy.png"),        QObject::tr("Copy"),                   Window);
        CustomMode      = new QAction(QIcon(),                             QObject::tr("Custom"),                 Window);
        Cut             = new QAction(QIcon(IconPath + "cut.png"),         QObject::tr("Cut"),                    Window);
        Donation        = new QAction(QIcon(),                             QObject::tr("Make a donation..."),     Window);
        FindAndReplace  = new QAction(QIcon(IconPath + "search.png"),      QObject::tr("Search..."),              Window);
        SelectFont      = new QAction(QIcon(IconPath + "font.png"),        QObject::tr("Fonts..."),               Window);
        Fullscreen      = new QAction(QIcon(IconPath + "fullscreen.png"),  QObject::tr("Fullscreen"),             Window);
        HighlightLine   = new QAction(QIcon(),                             QObject::tr("Highlight Current Line"), Window);
        License         = new QAction(QIcon(),                             QObject::tr("License..."),             Window);
        LineCount       = new QAction(QIcon(),                             QObject::tr("Line numbers"),           Window);
        MinimalMode     = new QAction(QIcon(),                             QObject::tr("Minimal Mode"),           Window);
        New             = new QAction(QIcon(IconPath + "new.png"),         QObject::tr("New"),                    Window);
        NormalMode      = new QAction(QIcon(),                             QObject::tr("Normal Mode"),            Window);
        Open            = new QAction(QIcon(IconPath + "open.png"),        QObject::tr("Open"),                   Window);
        Paste           = new QAction(QIcon(IconPath + "paste.png"),       QObject::tr("Paste"),                  Window);
        Print           = new QAction(QIcon(IconPath + "print.png"),       QObject::tr("Print..."),               Window);
        Quit            = new QAction(QIcon(IconPath + "close.png"),       QObject::tr("Exit"),                   Window);
        Redo            = new QAction(QIcon(IconPath + "redo.png"),        QObject::tr("Redo"),                   Window);
        Save            = new QAction(QIcon(IconPath + "save.png"),        QObject::tr("Save"),                   Window);
        SaveAs          = new QAction(QIcon(IconPath + "save-as.png"),     QObject::tr("Save As..."),             Window);
        SelectAll       = new QAction(QIcon(IconPath + "select-all.png"),  QObject::tr("Select All..."),          Window);
        SetReadOnly     = new QAction(QIcon(IconPath + "lock.png"),        QObject::tr("Set Read-Only"),          Window);
        ToggleStatusbar = new QAction(QIcon(),                             QObject::tr("Statusbar"),              Window);
        ToggleToolbar   = new QAction(QIcon(),                             QObject::tr("Toolbar"),                Window);
        Undo            = new QAction(QIcon(IconPath + "undo.png"),        QObject::tr("Undo"),                   Window);
        Contents        = new QAction(QIcon(),                             QObject::tr("View Help..."),              Window);
        WordWrap        = new QAction(QIcon(),                             QObject::tr("Word wrap"),              Window);
        ReportBug       = new QAction(QIcon(),                             QObject::tr("Report Bug..."),          Window);
        Website         = new QAction(QIcon(),                             QObject::tr("Website..."), Window);

        FullscreenSeparator  = new QAction(Window);
        SetReadOnlySeparator = new QAction(Window);
        FullscreenSeparator->setSeparator  (true);
        SetReadOnlySeparator->setSeparator (true);

        DefaultColorscheme  = new QAction(QObject::tr("Default"),  Window);
        CobaltColorscheme   = new QAction(QObject::tr("Cobalt"),   Window);
        KateColorscheme     = new QAction(QObject::tr("Kate"),     Window);
        OblivionColorscheme = new QAction(QObject::tr("Oblivion"), Window);
        TangoColorscheme    = new QAction(QObject::tr("Tango"),    Window);

        PlainText  = new QAction(QObject::tr("Plain text"),   Window);
        BashScript = new QAction(QObject::tr("Bash script"),  Window);
        C          = new QAction(QObject::tr("C/C++"),        Window);
        CSS        = new QAction(QObject::tr("CSS"),          Window);
        HTML       = new QAction(QObject::tr("HTML"),         Window);
        Java       = new QAction(QObject::tr("Java"),         Window);
        LaTeX      = new QAction(QObject::tr("LaTeX"),        Window);
        Python     = new QAction(QObject::tr("Python"),       Window);
        Vala       = new QAction(QObject::tr("Vala"),         Window);
        VBasic     = new QAction(QObject::tr("Visual Basic"), Window);

        DefaultColorscheme->setCheckable  (true);
        CobaltColorscheme->setCheckable   (true);
        KateColorscheme->setCheckable     (true);
        OblivionColorscheme->setCheckable (true);
        TangoColorscheme->setCheckable    (true);

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

        CustomMode->setCheckable      (true);
        HighlightLine->setCheckable   (true);
        LineCount->setCheckable       (true);
        MinimalMode->setCheckable     (true);
        NormalMode->setCheckable      (true);
        SetReadOnly->setCheckable     (true);
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
        ColorschemesGroup->addAction(KateColorscheme);
        ColorschemesGroup->addAction(OblivionColorscheme);
        ColorschemesGroup->addAction(TangoColorscheme);

        ColorSignalMapper = new QSignalMapper(Window);
        QObject::connect(DefaultColorscheme,  SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(CobaltColorscheme,   SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(KateColorscheme,     SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(OblivionColorscheme, SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));
        QObject::connect(TangoColorscheme,    SIGNAL(triggered()), ColorSignalMapper, SLOT(map()));

        ColorSignalMapper->setMapping(DefaultColorscheme,  1);
        ColorSignalMapper->setMapping(CobaltColorscheme,   2);
        ColorSignalMapper->setMapping(KateColorscheme,     3);
        ColorSignalMapper->setMapping(OblivionColorscheme, 4);
        ColorSignalMapper->setMapping(TangoColorscheme,    5);

        New->setShortcut             (QKeySequence::New);
        Open->setShortcut            (QKeySequence::Open);
        Save->setShortcut            (QKeySequence::Save);
        SaveAs->setShortcut          (QKeySequence::SaveAs);
        Print->setShortcut           (QKeySequence::Print);
        Quit->setShortcut            (QKeySequence::Quit);
        Undo->setShortcut            (QKeySequence::Undo);
        Redo->setShortcut            (QKeySequence::Redo);
        Cut->setShortcut             (QKeySequence::Cut);
        Copy->setShortcut            (QKeySequence::Copy);
        Paste->setShortcut           (QKeySequence::Paste);
        FindAndReplace->setShortcut  (QKeySequence::Find);
        SetReadOnly->setShortcut     (QKeySequence::AddTab);
        SelectAll->setShortcut       (QKeySequence::SelectAll);

        SelectFont->setShortcut      (QKeySequence(Qt::ALT   + Qt::Key_F));
        MinimalMode->setShortcut     (QKeySequence(Qt::ALT   + Qt::Key_M));
        NormalMode->setShortcut      (QKeySequence(Qt::ALT   + Qt::Key_N));
        ToggleStatusbar->setShortcut (QKeySequence(Qt::ALT   + Qt::Key_S));
        ToggleToolbar->setShortcut   (QKeySequence(Qt::ALT   + Qt::Key_T));
        WordWrap->setShortcut        (QKeySequence(Qt::ALT   + Qt::Key_W));
        Fullscreen->setShortcut      (QKeySequence(Qt::SHIFT + Qt::Key_F));
        HighlightLine->setShortcut   (QKeySequence(Qt::SHIFT + Qt::Key_H));

        // List the About Qt action in the help menu (in Mac OS X)
        AboutQt->setMenuRole(QAction::NoRole);

        if (Shared::CheckOS() != 3) {
            AboutTextpad->setIconVisibleInMenu   (false);
            Copy->setIconVisibleInMenu           (false);
            Cut->setIconVisibleInMenu            (false);
            FindAndReplace->setIconVisibleInMenu (false);
            SelectFont->setIconVisibleInMenu     (false);
            Fullscreen->setIconVisibleInMenu     (false);
            New->setIconVisibleInMenu            (false);
            Open->setIconVisibleInMenu           (false);
            Paste->setIconVisibleInMenu          (false);
            Print->setIconVisibleInMenu          (false);
            Quit->setIconVisibleInMenu           (false);
            Redo->setIconVisibleInMenu           (false);
            Save->setIconVisibleInMenu           (false);
            SaveAs->setIconVisibleInMenu         (false);
            SelectAll->setIconVisibleInMenu      (false);
            SetReadOnly->setIconVisibleInMenu    (false);
            Undo->setIconVisibleInMenu           (false);
            Contents->setIconVisibleInMenu       (false);
            ReportBug->setIconVisibleInMenu      (false);
        }
    }

    void CreateMenubar(QMainWindow *Window) {
        // Create the main menus
        File   = Window->menuBar()->addMenu(QObject::tr("File"));
        Edit   = Window->menuBar()->addMenu(QObject::tr("Edit"));
        Format = Window->menuBar()->addMenu(QObject::tr("Format"));
        View   = Window->menuBar()->addMenu(QObject::tr("View"));
        Help   = Window->menuBar()->addMenu(QObject::tr("Help"));

        // Setup the file menu
        File->addAction(New);
        File->addAction(Open);
        File->addAction(Save);
        File->addSeparator();
        File->addAction(SaveAs);
        File->addSeparator();
        File->addAction(Print);
        File->addSeparator();
        RecentFiles = File->addMenu(QObject::tr("Recent Files..."));
        File->addSeparator();
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
        Edit->addAction(SetReadOnly);

        // Setup the Format menu
        Format->addAction(SelectFont);
        Format->addSeparator();
        Format->addAction(WordWrap);

        // Setup the View menu
        View->addAction(ToggleToolbar);
        View->addAction(ToggleStatusbar);

        View->addSeparator();
        Modes = View->addMenu(QObject::tr("Modes"));
        Modes->addAction(NormalMode);
        Modes->addAction(MinimalMode);
        Modes->addSeparator();
        Modes->addAction(CustomMode);

        Advanced = View->addMenu(QObject::tr("Advanced"));
        Advanced->addAction(HighlightLine);
        Advanced->addAction(LineCount);
        Advanced->addSeparator();

        Colorschemes = Advanced->addMenu(QObject::tr("Color Schemes"));
        Colorschemes->addAction(DefaultColorscheme);
        Colorschemes->addSeparator();
        Colorschemes->addAction(CobaltColorscheme);
        Colorschemes->addAction(KateColorscheme);
        Colorschemes->addAction(OblivionColorscheme);
        Colorschemes->addAction(TangoColorscheme);

        HighlightMode = Advanced->addMenu(QObject::tr("Highlight Mode"));
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
        View->addAction(Fullscreen);

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

    void CreateToolbar(QMainWindow *Window) {
        // Create the Toolbar
        Toolbar = Window->addToolBar("Main Toolbar");
        Toolbar->setMovable(false);

        // Mac OS X Specific tweaks
        if (Shared::CheckOS() == 1) {
            Window->setUnifiedTitleAndToolBarOnMac(true);
            Toolbar->setMinimumHeight(32);
            Toolbar->setMaximumHeight(32);
        }

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
        Toolbar->addAction(FindAndReplace);
    }

    void SetupUI(QMainWindow *Window) {
        CreateActions(Window);
        CreateMenubar(Window);
        CreateToolbar(Window);
    }
};

namespace Ui {
class MainWindow: public ui {};
}

QT_END_NAMESPACE

#endif

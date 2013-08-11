// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/application.hh"

Application::Application (int & argc, char **argv) : QApplication(argc, argv)
{
    setApplicationName("Textpad Editor");
    setApplicationVersion("0.7.4.1");

    QString Arguments;
    QString FileLocation;
    Window = new MainWindow();

    if (argc != 1) {
        for (int i = 0; i < argc; i++)
            Arguments = argv[i];

        if (Shared::CheckOS() == 1)
            Arguments.replace("--args", "");

        if (Arguments == "%U") {
            FileLocation.clear();
            Window->show();
            Window->TextEditor->New();
        }

        else {
            FileLocation = Arguments;
            Window->show();
            Window->TextEditor->OpenFile(FileLocation);
        }
    }

    else {
        FileLocation.clear();
        Window->show();
        Window->TextEditor->New();
    }
}

Application::~Application() {}

void Application::LoadFile(const QString &FileName)
{
    if (!FileName.isEmpty())
        Window->TextEditor->OpenFile(FileName);
    else
        Window->TextEditor->New();
}

bool Application::event(QEvent *Event)
{
    switch (Event->type())
    {
    case QEvent::FileOpen:
        LoadFile(static_cast<QFileOpenEvent *>(Event)->file());
        return true;
        break;
    default:
        return QApplication::event(Event);
    }
}

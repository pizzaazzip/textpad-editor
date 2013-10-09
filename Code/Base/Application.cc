// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Authors.md" file that comes with this distribution

#include "Code/Base/Application.hh" 

Application::Application (int & argc, char **argv) : QApplication(argc, argv) {
    // Setup the name, version and icon of the application
    setApplicationName("Textpad Editor");
    setApplicationVersion("0.8.1");
    setWindowIcon(QIcon(":/Icons/Resources/Icons/48x48/TextpadEditor.png"));

    // Prepare a string that will be used to determine the arguments that where passed to the program
    QString Arguments;

    // Declare a new MainWindow
    mainWindow = new MainWindow;

    // Load the geometry settings
    QSettings Settings("Textpad Editor", "WindowData");
    mainWindow->setGeometry(Settings.value("Window.Geometry",  QRect(150, 150, 800, 400)).toRect());

    // Check that we actually received arguments
    if (argc != 1) {
        // Convert the received arguments to a string
        for (int i = 0; i < argc; i++)
            Arguments = argv[i];

        // Remove the "--args" argument in Mac OS X
        if (Shared::CheckOS() == "Mac")
            Arguments.replace("--args", "");

        // Do nothing if we receive this argument (mainly used in Linux)
        if (Arguments == "%U") {
            Arguments.clear();
            return;
        }

        // Open a file (or create one) with the name specified in the arguments
        else {
            mainWindow->TextEdit->OpenFile(Arguments);
            return;
        }
    }

    // Setup the first MainWindow
    mainWindow->CreateNewWindow(mainWindow);
}

Application::~Application() {}

void Application::LoadFile(const QString &Filename) {
    // Check that the file specified exists
    if  (!Filename.isEmpty()) {
        // Check if we need to open the file in a new window or not
        if (mainWindow->TextEdit->Filename.isEmpty() && !mainWindow->TextEdit->document()->isModified())
            mainWindow->TextEdit->OpenFile(Filename);

        else {
            // Open the file in a new window
            MainWindow *NewWindow = new MainWindow();
            NewWindow->TextEdit->OpenFile(Filename);

            // Make sure that the NewWindow connects with all the other instanced of MainWindow
            mainWindow->CreateNewWindow(NewWindow);
        }
    }
}

bool Application::event(QEvent *Event) {
    switch (Event->type()) {
    case QEvent::FileOpen:
        LoadFile(static_cast<QFileOpenEvent *>(Event)->file());
        return true;
        break;
    default:
        return QApplication::event(Event);
    }
}


int main(int argc, char *argv[]) {
    Application Textpad(argc, argv);

    // Decide if there is another instance of Textpad already running
    QSharedMemory SharedMemory("Textpad Editor (textpad-editor)");

    // There isn't another instance of Textpad runnning
    if (SharedMemory.create(1) && SharedMemory.error() != QSharedMemory::AlreadyExists)
        return Textpad.exec();

    // There is already an instance of Textpad running
    else
    {
        if (SharedMemory.attach())
            return Textpad.exec();

        else {
            // Something wicked happened and QSharedMemory could not attach the process...
            Textpad.mainWindow->hide();
            QMessageBox MessageBox;
            MessageBox.setWindowTitle("Warning");
            MessageBox.setText("<b>There is another instance of Textpad already running</b>");
            MessageBox.setInformativeText("We tried to do some magic, but we failed,"
                                          "would you like to open a new instance?");
            MessageBox.setStandardButtons(QMessageBox::Open | QMessageBox::Close);
            MessageBox.setIcon(QMessageBox::Warning);
            int Return = MessageBox.exec();

            if (Return == QMessageBox::Open) {
                Textpad.mainWindow->show();
                return Textpad.exec();
            }
        }
    }

    return 0;
}

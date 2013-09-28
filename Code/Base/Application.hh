#ifndef APPLICATION_HH
#define APPLICATION_HH

#include "Code/MainWindow/MainWindow.hh"

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    MainWindow *mainWindow;
    virtual ~Application();

protected:
    bool event(QEvent *Event);

private:
    void LoadFile(const QString &Filename);

};

#endif

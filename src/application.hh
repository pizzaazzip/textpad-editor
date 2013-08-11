#ifndef APPLICATION_HH
#define APPLICATION_HH

#include "src/mainwindow.hh"

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    virtual ~Application();

protected:
    bool event(QEvent *Event);

private:
    void LoadFile(const QString &FileName);
    MainWindow *Window;
};

#endif

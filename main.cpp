#include <QApplication>
#include <MainWindow.h>

MainWindow * mainWindow;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow = new MainWindow();

    return a.exec();
}

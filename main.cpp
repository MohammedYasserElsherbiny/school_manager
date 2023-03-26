#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainPanel = new MainWindow();

    return a.exec();
}

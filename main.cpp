#include <QApplication>
#include <panel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Panel *mainPanel = new Panel();

    return a.exec();
}

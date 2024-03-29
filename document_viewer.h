#ifndef DOCUMENT_VIEWER_H
#define DOCUMENT_VIEWER_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <QProcess>
#include <set>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtCore/QFileInfo>
#include <QTextDocument>

using namespace std;

class Document_Viewer : public QGraphicsView
{
public:
    Document_Viewer();
    void show_window();

private:
    QPushButton *next_document_btn, *previous_document_btn;

    QPushButton *load_file, *remove_file, *print_file;


    QGraphicsProxyWidget *next_document_proxy, *previous_document_proxy;

    QGraphicsProxyWidget *load_file_proxy, *remove_file_proxy, *print_file_proxy;

    fstream file;

    QProcess process;

    void showGradeOptions();
    void loadFile ();
    string currentItem ();
    void previousItem ();
    void nextItem ();

    void removeFromFile ();
    void itemOpener ();
    void moveToFolder ();
    void printDocument(const QString& filePath);
};

#endif // DOCUMENT_VIEWER_H

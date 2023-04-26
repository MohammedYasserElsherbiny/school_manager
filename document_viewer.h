#ifndef DOCUMENT_VIEWER_H
#define DOCUMENT_VIEWER_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Document_Viewer : public QGraphicsView
{
public:
    Document_Viewer();
    void show_window();

private:
    QPushButton *next_document_btn, *previous_document_btn;
    QPushButton *document_preview_btn;
    QPushButton *load_file, *remove_file, *print_file;


    QGraphicsProxyWidget *next_document_proxy, *previous_document_proxy;
    QGraphicsProxyWidget *document_preview_proxy;
    QGraphicsProxyWidget *load_file_proxy, *remove_file_proxy, *print_file_proxy;

    QString file_name, storge_file ;

    fstream file;

    int place;

    vector <string> names;

    void showGradeOptions();
    void loadFile ();
    string currentItem ();
    void previousItem ();
    void nextItem ();
    void fileNames ();
    void setMainItem ();


};

#endif // DOCUMENT_VIEWER_H

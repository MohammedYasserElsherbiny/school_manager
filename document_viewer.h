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

    QString file_name ;

    map<string,fstream> storge_files;
                //number of the line ,  path , name of the file , extention of the file
    vector< map < int , pair < string , pair < string , string > > > > names;

    set <string> temp_storge_file_names;
    vector<string>storge_file_names;

    fstream file;

    int place;

    QProcess process;




    void showGradeOptions();
    void loadFile ();
    string currentItem ();
    void previousItem ();
    string currentName ();
    void nextItem ();
    void fileNames ();
    void setMainItem ();
    void removeFromFile ();
    void itemOpener ();
    void generateFolders ();
    void generateFiles ();
    int setFileNum ();
    void fileOpener ();
    void fileCloser ();

};

#endif // DOCUMENT_VIEWER_H

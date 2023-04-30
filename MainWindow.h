#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QFile>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QBrush>
#include <QImage>
#include <gender_selection.h>
#include <document_viewer.h>
#include <gradeselection.h>
#include <gradeoptions.h>
#include <string>

class MainWindow : public QGraphicsView
{
public:
    MainWindow();
    void initWindows ();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;

    QPushButton *backBtn;
    QGraphicsProxyWidget *backBtnProxy;

    // Windows declarations
    Gender_Selection *gender_selection_window;
    Document_Viewer *document_viewer;
    GradeSelection *grade_selection_window;
    GradeOptions *grade_options_window;



    string gender,grade,option;

    //for document viwer
    QString file_name ;

    map<string,fstream> storge_files;
                //number of the line ,  path , name of the file , extention of the file
    vector< map < int , pair < string , pair < string , string > > > > names;

    map<map < int , pair < string , pair < string , string > > > ,int >freqNames;

    set <string> temp_storge_file_names;
    vector<string>storge_file_names;

    int place;

    QPushButton *document_preview_btn;
    QGraphicsProxyWidget *document_preview_proxy;


    // Window functions
    void clearScene();
    void show_window();

    //for document viwer
    void generateFolders ();
    void generateFiles ();
    void fileOpener ();
    int setFileNum ();
    void fileNames ();
    void fileCloser ();
    void setMainItem ();
    string currentName ();





private:
    void showGenderSelectionWindow();
    QPushButton *startBtn;
    QGraphicsProxyWidget *startBtnProxy;
};

#endif // MAINWINDOW_H

#include "document_viewer.h"
#include "MainWindow.h"
#include <gradeoptions.h>
#include <MainWindow.h>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <fstream>
#include <ostream>
#include <istream>
#include <algorithm>
#include <filesystem>
#include <unistd.h>
#include <cstdio>
//#include <winbase.h>
//#include <QProcess>
//#include <QDir>
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <winuser.h>
using namespace std;
//file_name storge_file loadFile abs(place)
extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{


    mainWindow->place =0;

    previous_document_btn = new QPushButton("<");
    next_document_btn = new QPushButton(">");
    mainWindow->document_preview_btn = new QPushButton();
    //mainWindow->setMainItem();

    load_file = new QPushButton("اضافة");
    remove_file = new QPushButton("حذف");
    print_file = new QPushButton("طباعة");

    load_file->hide();
    remove_file->hide();
    print_file->hide();
    previous_document_btn->hide();
    next_document_btn->hide();

    QObject::connect(load_file, &QPushButton::clicked, this, & Document_Viewer::loadFile);
    QObject::connect(next_document_btn, &QPushButton::clicked, this, & Document_Viewer::nextItem);
    QObject::connect(previous_document_btn, &QPushButton::clicked, this, & Document_Viewer::previousItem);
    QObject::connect(remove_file, &QPushButton::clicked, this, & Document_Viewer::removeFromFile);
    QObject::connect(mainWindow->document_preview_btn, &QPushButton::clicked, this, & Document_Viewer::itemOpener);


}

void Document_Viewer::show_window()
{

    previous_document_proxy = mainWindow->scene->addWidget(previous_document_btn);
    previous_document_proxy->setMinimumWidth(25);
    previous_document_proxy->resize(
        25,
        150
    );
    previous_document_proxy->setPos(
        mainWindow->width * 25 / 100 - previous_document_proxy->boundingRect().width()/2,
        mainWindow->height * 65 / 100 - previous_document_proxy->boundingRect().height()/2
    );

    next_document_proxy = mainWindow->scene->addWidget(next_document_btn);
    next_document_proxy->setMinimumWidth(25);
    next_document_proxy->resize(
        25,
        150
    );
    next_document_proxy->setPos(
        mainWindow->width * 75 / 100 - next_document_proxy->boundingRect().width()/2,
        mainWindow->height * 65 / 100 - next_document_proxy->boundingRect().height()/2
    );

    mainWindow->document_preview_proxy = mainWindow->scene->addWidget(mainWindow->document_preview_btn);
    mainWindow->document_preview_proxy->resize(
        mainWindow->width * 45 / 100,
        150
    );
    mainWindow->document_preview_proxy->setPos(
        mainWindow->width/2 - mainWindow->document_preview_proxy->boundingRect().width()/2,
        mainWindow->height * 65 / 100 - mainWindow->document_preview_proxy->boundingRect().height()/2
    );

    load_file_proxy = mainWindow->scene->addWidget(load_file);
    remove_file_proxy = mainWindow->scene->addWidget(remove_file);
    print_file_proxy = mainWindow->scene->addWidget(print_file);

    int bottomBtnWidth = mainWindow->width * 50 / 100 / 3;
    load_file_proxy->resize(bottomBtnWidth, 25);
    remove_file_proxy->resize(bottomBtnWidth, 25);
    print_file_proxy->resize(bottomBtnWidth, 25);

    load_file_proxy->setPos(
        mainWindow->width * 25 / 100 - 12,
        mainWindow->height * 65 / 100 + 75 + 5
    );

    remove_file_proxy->setPos(
        mainWindow->width * 25 / 100 + bottomBtnWidth,
        mainWindow->height * 65 / 100 + 75 + 5
    );

    print_file_proxy->setPos(
        mainWindow->width * 25 / 100 + bottomBtnWidth*2 + 12,
        mainWindow->height * 65 / 100 + 75 + 5
    );

    load_file->show();
    remove_file->show();
    print_file->show();
    previous_document_btn->show();
    next_document_btn->show();

    mainWindow->backBtn->show();
    mainWindow->document_preview_btn->show();


    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, &Document_Viewer::showGradeOptions);
}

void Document_Viewer::showGradeOptions()
{
    mainWindow->clearScene();
    QObject::disconnect(mainWindow->backBtn, &QPushButton::clicked, this, &Document_Viewer::showGradeOptions);
    mainWindow->grade_options_window->show_window();
}

void Document_Viewer::loadFile()
{
    mainWindow->fileOpener();

    mainWindow->file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    mainWindow->storge_files[mainWindow->storge_file_names[mainWindow->setFileNum()]] << mainWindow->file_name.toStdString()<<endl ;

    //set the file to the folder
    mainWindow->fileNames();
    mainWindow->setMainItem();
    moveToFolder();
    mainWindow->fileCloser();

}

string Document_Viewer::currentItem()
{
    map < int , pair < string , pair < string , string > > > temp;
    temp=mainWindow->names[mainWindow->place%(mainWindow->names.size())];
    return temp[mainWindow->place%(mainWindow->names.size())].first;
}



void Document_Viewer::previousItem()
{
    mainWindow->place--;
    mainWindow->setMainItem();
}

void Document_Viewer::nextItem()
{
    mainWindow->place++;
    mainWindow->setMainItem();
}


void Document_Viewer::removeFromFile()
{


    string line,emptyString="";
    string path=mainWindow->storge_file_names[mainWindow->setFileNum()],tempPath="temp.txt";
    string eraseLine=currentItem();
    ifstream fin;

    fin.open(path);

    ofstream temp;
    temp.open(tempPath, ios::out|ios::binary);

    while (getline(fin, line))
    {
            if (line != eraseLine)
                temp << line << std::endl;
    }


    temp.close();
    fin.close();
    mainWindow->fileCloser();



    remove(path.c_str());
    rename(tempPath.c_str(), path.c_str());

    const char *ttemp=(mainWindow->names[mainWindow->place%(mainWindow->names.size())][mainWindow->place%(mainWindow->names.size())].first).c_str();
    int s=remove(ttemp);

    //(mainWindow->names[mainWindow->setFileNum()]).erase(mainWindow->place%(mainWindow->names.size()));
    mainWindow->names.erase(mainWindow->names.begin()+((mainWindow->place%(mainWindow->names.size()))));
    mainWindow->setMainItem();
}

void Document_Viewer::itemOpener()
{
    mainWindow->fileOpener();
    if(filesystem::is_empty(mainWindow->storge_file_names[mainWindow->setFileNum()]))
            return ;
    map < int , pair < string , pair < string , string > > >  temp12;
    int tempIdx;
    if(abs(mainWindow->place)==(int)(mainWindow->names.size()-1))
    {
        mainWindow->place=0;
    }
    if(mainWindow->place<0)
    {
        tempIdx=mainWindow->names.size()+mainWindow->place;
    }
    else
    {
        tempIdx=mainWindow->place%mainWindow->names.size();
    }
    temp12=mainWindow->names[tempIdx];
    string PATH;
    for(auto p : temp12)
    {
        if(p.second.second.second =="")
            continue;
        PATH=p.second.first;
    }

    PATH="\""+PATH+"\"";
    const char *c=(PATH).c_str();
    system(c);
    //WinExec(c,SW_HIDE );
    //SW_HIDE
    mainWindow->fileCloser();
}

void Document_Viewer::moveToFolder()
{
    string newPath=mainWindow->setFolderDirectorie();
    string oldPath;
    map < int , pair < string , pair < string , string > > > temp;
    int tempIdx;
    if(abs(mainWindow->place)==(int)(mainWindow->names.size()-1)&&(mainWindow->place<0))
    {
        mainWindow->place=0;
    }
    if(mainWindow->place<0)
    {
        tempIdx=mainWindow->names.size()+mainWindow->place;
    }
    else
    {
        tempIdx=mainWindow->place%mainWindow->names.size();
    }
    temp=mainWindow->names[mainWindow->names.size()-1];
    oldPath=temp[mainWindow->names.size()-1].first;

    newPath=newPath+"/"+temp[mainWindow->names.size()-1].second.first+"."+temp[mainWindow->names.size()-1].second.second;


    rename(oldPath.c_str(), newPath.c_str());
}

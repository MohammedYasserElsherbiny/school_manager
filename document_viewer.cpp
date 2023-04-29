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
//#include <QProcess>
//#include <QDir>
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <winuser.h>
using namespace std;
//file_name storge_file loadFile
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


    mainWindow->backBtn->show();

    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, &Document_Viewer::showGradeOptions);


}

void Document_Viewer::showGradeOptions()
{
    mainWindow->clearScene();
    mainWindow->grade_options_window->show_window();
}

void Document_Viewer::loadFile()
{
    mainWindow->fileOpener();

    mainWindow->file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    mainWindow->storge_files[mainWindow->storge_file_names[mainWindow->setFileNum()]] << mainWindow->file_name.toStdString()<<endl ;

    mainWindow->fileNames();
    documentViewerIconAndName();

}

string Document_Viewer::currentItem()
{
    return mainWindow->names[mainWindow->setFileNum()][mainWindow->place%(mainWindow->names.size())].first;
}



void Document_Viewer::previousItem()
{
    mainWindow->place--;
    documentViewerIconAndName();
}

void Document_Viewer::nextItem()
{
    mainWindow->place++;
    documentViewerIconAndName();
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
    mainWindow->fileCloser();



    remove(path.c_str());
    rename(tempPath.c_str(), path.c_str());

    const char *ttemp=(mainWindow->names[mainWindow->setFileNum()][mainWindow->place%(mainWindow->names.size())].first).c_str();
    int s=remove(ttemp);

    mainWindow->names[mainWindow->setFileNum()].erase(mainWindow->place%(mainWindow->names.size()));

    documentViewerIconAndName();
}

void Document_Viewer::itemOpener()
{
    if(filesystem::is_empty(mainWindow->storge_file_names[mainWindow->setFileNum()]))
            return ;

    string PATH=mainWindow->names[mainWindow->setFileNum()][mainWindow->place%(mainWindow->names.size())].first;
    PATH="\""+PATH+"\"";
    const char *c=(PATH).c_str();
    system(c);
    //WinExec(c,SW_HIDE );
    //SW_HIDE
}

void Document_Viewer::documentViewerIconAndName()
{
//    string extention;//= mainWindow->setMainItem();
//    if(extention=="")
//    {
//        mainWindow->document_preview_btn->setText("لا يوجد ملفات");
//        mainWindow->document_preview_btn->setIcon(QIcon());
//    }
//    else
//    {
//        mainWindow->document_preview_btn->setText(QString::fromStdString(currentName()));

//        if(extention=="txt")
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon(":/Assets/Images/images.png"));
//            mainWindow->document_preview_btn->setIconSize(QSize(65, 65));
//        }
//        else if(extention=="jpg")
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon(":/Assets/Images/Photos-new-icon.png"));
//            mainWindow->document_preview_btn->setIconSize(QSize(65, 65));
//        }
//        else if(extention=="xls")
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon(":/Assets/Images/Microsoft Excel Vector PNG Images, Microsoft Excel Icon, Excel Icons, Microsoft Icons, Microsoft PNG Image For Free Download.jpg"));
//            mainWindow->document_preview_btn->setIconSize(QSize(65, 65));
//        }
//        else if(extention=="ppt")
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon(":/Assets/Images/Powerpoints Clipart Vector, Powerpoint Icon, Powerpoint Icons, Microsoft, Azure PNG Image For Free Download.jpg"));
//            mainWindow->document_preview_btn->setIconSize(QSize(65, 65));
//        }
//        else if(extention=="doc")
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon(":/Assets/Images/word.jpg"));
//            mainWindow->document_preview_btn->setIconSize(QSize(65, 65));
//        }
//        else
//        {
//            mainWindow->document_preview_btn->setIcon(QIcon());
//        }

//    }

    /*void Document_Viewer::setMainItem()
{
    if(filesystem::is_empty("storge.txt"))
    if(filesystem::is_empty(storge_file_names[setFileNum()]))
    {
        document_preview_btn->setText("لا يوجد ملفات");
        document_preview_btn->setIcon(QIcon());
        return ;
    }
    else
    {
        document_preview_btn->setText(QString::fromStdString(currentName()));
    }

    if(names[place%names.size()].second.second=="txt")
    if(names[setFileNum()][place%names.size()].second.second=="txt")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/images.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if((names[place%names.size()].second.second=="bmp")||(names[place%names.size()].second.second=="jpg")||(names[place%names.size()].second.second=="png"))
    else if((names[setFileNum()][place%names.size()].second.second=="bmp")||(names[setFileNum()][place%names.size()].second.second=="jpg")||(names[setFileNum()][place%names.size()].second.second=="png"))
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Photos-new-icon.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="xlsx")
    else if(names[setFileNum()][place%names.size()].second.second=="xlsx"||names[setFileNum()][place%names.size()].second.second=="csv"||names[setFileNum()][place%names.size()].second.second=="xls")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Microsoft Excel Vector PNG Images, Microsoft Excel Icon, Excel Icons, Microsoft Icons, Microsoft PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="pptx")
    else if(names[setFileNum()][place%names.size()].second.second=="pptx"||names[setFileNum()][place%names.size()].second.second=="ppt"||names[setFileNum()][place%names.size()].second.second=="pot")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Powerpoints Clipart Vector, Powerpoint Icon, Powerpoint Icons, Microsoft, Azure PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="docx")
    else if(names[setFileNum()][place%names.size()].second.second=="docx"||names[setFileNum()][place%names.size()].second.second=="doc")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/word.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else
    {
        document_preview_btn->setIcon(QIcon());
    }
}*/
}












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
extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{

    file.open("storge.txt",ios::app);
    if(!filesystem::is_empty("storge.txt"))
        fileNames();
    place =0;

    previous_document_btn = new QPushButton("<");
    next_document_btn = new QPushButton(">");
    document_preview_btn = new QPushButton();
    setMainItem();

    load_file = new QPushButton("Load");
    remove_file = new QPushButton("Remove");
    print_file = new QPushButton("Print");


    QObject::connect(load_file, &QPushButton::clicked, this, & Document_Viewer::loadFile);
    QObject::connect(next_document_btn, &QPushButton::clicked, this, & Document_Viewer::nextItem);
    QObject::connect(previous_document_btn, &QPushButton::clicked, this, & Document_Viewer::previousItem);
    QObject::connect(remove_file, &QPushButton::clicked, this, & Document_Viewer::removeFromFile);
    QObject::connect(document_preview_btn, &QPushButton::clicked, this, & Document_Viewer::fileOpener);


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

    document_preview_proxy = mainWindow->scene->addWidget(document_preview_btn);
    document_preview_proxy->resize(
        mainWindow->width * 45 / 100,
        150
    );
    document_preview_proxy->setPos(
        mainWindow->width/2 - document_preview_proxy->boundingRect().width()/2,
        mainWindow->height * 65 / 100 - document_preview_proxy->boundingRect().height()/2
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
    file.open("storge.txt",ios::app);

    file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    file << file_name.toStdString()<<endl ;

    fileNames();
    setMainItem();

}

string Document_Viewer::currentItem()
{
    return names[place%names.size()].first;
}

string Document_Viewer::currentName()
{
    return names[place%names.size()].second.first;
}

void Document_Viewer::previousItem()
{
    place--;
    setMainItem();
}

void Document_Viewer::nextItem()
{
    place++;
    setMainItem();
}

void Document_Viewer::setMainItem()
{
    if(filesystem::is_empty("storge.txt"))
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
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/images.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if((names[place%names.size()].second.second=="bmp")||(names[place%names.size()].second.second=="jpg")||(names[place%names.size()].second.second=="png"))
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Photos-new-icon.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="xlsx")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Microsoft Excel Vector PNG Images, Microsoft Excel Icon, Excel Icons, Microsoft Icons, Microsoft PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="pptx")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Powerpoints Clipart Vector, Powerpoint Icon, Powerpoint Icons, Microsoft, Azure PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[place%names.size()].second.second=="docx")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/word.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
}

void Document_Viewer::removeFromFile()
{

    //removeItem();
    string line,emptyString="";
    string path="storge.txt",tempPath="temp.txt";
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


    const char * p = path.c_str();
    const char * tp = tempPath.c_str();
    remove(path.c_str());
    rename(tempPath.c_str(), path.c_str());

    const char *ttemp=(names[place%names.size()].first).c_str();
    int s=remove(ttemp);

    names.erase(place%names.size());

    setMainItem();
}

void Document_Viewer::fileOpener()
{
    if(filesystem::is_empty("storge.txt"))
            return ;
    string PATH=names[place%names.size()].first;
    PATH="\""+PATH+"\"";
    const char *c=(PATH).c_str();
    system(c);
    //WinExec(c,SW_HIDE );
    //SW_HIDE
}

void Document_Viewer::removeItem()
{


    string disk,dir,itemName;
    bool flag=false;
    disk.push_back(names[place%names.size()].first[0]);
    disk.push_back(names[place%names.size()].first[1]);
    for(int i=names[place%names.size()].first.size()-1;i>=0;i--)
    {
        string temp=names[place%names.size()].first;
        if(i==2)
        {
            break;
        }
        if(flag)
        {
            dir.push_back(temp[i]);
        }

        if(temp[i]=='/')
        {
            flag=true;
        }
        else
        {
            continue;
        }

    }
    reverse(dir.begin(),dir.end());
    const char *temp=(names[place%names.size()].first).c_str();
    int s=remove(temp);
}

void Document_Viewer::fileNames()
{

    string path;
    int tempPlace=0;
    ifstream ifile("storge.txt");
    while(getline(ifile, path))
    {

        string name;
        string exten;
        bool dotFlag= false;
        int path_size=path.size();
        for(int i=path_size-1;i>=0;i--)
        {
            if(path[i]=='.')
            {
                dotFlag= true;
                reverse(exten.begin(),exten.end());
                continue;
            }

            if(!dotFlag)
            {
                exten.push_back(path[i]);
                continue;
            }

            if(path[i]=='/')
            {
                break;
            }

            name.push_back(path[i]);
        }

        reverse(name.begin(),name.end());

        names[tempPlace].first=path;
        names[tempPlace].second.first=name;
        names[tempPlace].second.second=exten;
        tempPlace++;
    }
    file.close ();
}




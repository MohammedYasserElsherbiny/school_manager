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
//file_name storge_file
extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{

    generateFolders();
    generateFiles();
    //fileOpener();
    if(!filesystem::is_empty(storge_file_names[setFileNum()]))
        fileNames();
    place =0;

    previous_document_btn = new QPushButton("<");
    next_document_btn = new QPushButton(">");
    document_preview_btn = new QPushButton();
    setMainItem();

    load_file = new QPushButton("اضافة");
    remove_file = new QPushButton("حذف");
    print_file = new QPushButton("طباعة");


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
    fileOpener();

    file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    file << file_name.toStdString()<<endl ;

    fileNames();
    setMainItem();

}

string Document_Viewer::currentItem()
{
    return names[setFileNum()][place%names.size()].first;
}

string Document_Viewer::currentName()
{
    return names[setFileNum()][place%names.size()].second.first;
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

    if(names[setFileNum()][place%names.size()].second.second=="txt")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/images.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if((names[setFileNum()][place%names.size()].second.second=="bmp")||(names[setFileNum()][place%names.size()].second.second=="jpg")||(names[setFileNum()][place%names.size()].second.second=="png"))
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Photos-new-icon.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[setFileNum()][place%names.size()].second.second=="xlsx"||names[setFileNum()][place%names.size()].second.second=="csv"||names[setFileNum()][place%names.size()].second.second=="xls")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Microsoft Excel Vector PNG Images, Microsoft Excel Icon, Excel Icons, Microsoft Icons, Microsoft PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[setFileNum()][place%names.size()].second.second=="pptx"||names[setFileNum()][place%names.size()].second.second=="ppt"||names[setFileNum()][place%names.size()].second.second=="pot")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Powerpoints Clipart Vector, Powerpoint Icon, Powerpoint Icons, Microsoft, Azure PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else if(names[setFileNum()][place%names.size()].second.second=="docx"||names[setFileNum()][place%names.size()].second.second=="doc")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/word.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else
    {
        document_preview_btn->setIcon(QIcon());
    }
}

void Document_Viewer::removeFromFile()
{


    string line,emptyString="";
    string path=storge_file_names[setFileNum()],tempPath="temp.txt";
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
    fileCloser();


    const char * p = path.c_str();
    const char * tp = tempPath.c_str();
    remove(path.c_str());
    rename(tempPath.c_str(), path.c_str());

    const char *ttemp=(names[setFileNum()][place%names.size()].first).c_str();
    int s=remove(ttemp);

    names[setFileNum()].erase(place%names.size());

    setMainItem();
}

void Document_Viewer::itemOpener()
{
    if(filesystem::is_empty(storge_file_names[setFileNum()]))
            return ;

    string PATH=names[setFileNum()][place%names.size()].first;
    PATH="\""+PATH+"\"";
    const char *c=(PATH).c_str();
    system(c);
    //WinExec(c,SW_HIDE );
    //SW_HIDE
}

void Document_Viewer::generateFolders()
{

    //male
    filesystem::create_directories("C:/school_manager/male/Primary/additional");
    filesystem::create_directories("C:/school_manager/male/Primary/Circular");
    filesystem::create_directories("C:/school_manager/male/Primary/Plan");
    filesystem::create_directories("C:/school_manager/male/Primary/Reports");
    filesystem::create_directories("C:/school_manager/male/Intermediate/additional");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Circular");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Plan");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Reports");
    filesystem::create_directories("C:/school_manager/male/High school/additional");
    filesystem::create_directories("C:/school_manager/male/High school/Circular");
    filesystem::create_directories("C:/school_manager/male/High school/Plan");

    //female
    filesystem::create_directories("C:/school_manager/female/Primary/additional");
    filesystem::create_directories("C:/school_manager/female/Primary/Circular");
    filesystem::create_directories("C:/school_manager/female/Primary/Plan");
    filesystem::create_directories("C:/school_manager/female/Primary/Reports");
    filesystem::create_directories("C:/school_manager/female/Intermediate/additional");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Circular");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Plan");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Reports");
    filesystem::create_directories("C:/school_manager/female/High school/additional");
    filesystem::create_directories("C:/school_manager/female/High school/Circular");
    filesystem::create_directories("C:/school_manager/female/High school/Plan");
    filesystem::create_directories("C:/school_manager/female/High school/Reports");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/additional");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Circular");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Plan");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Reports");


}

void Document_Viewer::generateFiles()
{
    string male="Male",female="Female",add="Additional",cir="Circular",pla="Plan",repor="Report",kin="Kinder",inter="Intermediate",high="High school",pri="Primary";

    for(int i=0;i<2;i++)
    {
        string temp="Storge";

        if(i==1)
        {
            temp+=male;
        }
        else
        {
            temp+=female;
        }

        vector <string> fourTemp;
        for(int j=0;j<4;j++)
        {
            fourTemp.push_back(temp+pri);
            //break;


            fourTemp.push_back(temp+inter);
            //break;


            fourTemp.push_back(temp+high);
            //break;

            if(i!=1)
                fourTemp.push_back(temp+kin);
            //break;


            vector <string> lastTemp;
            for(int l=0;l<fourTemp.size()*4;l++)
            {
                if(l<4)
                {
                    lastTemp.push_back(fourTemp[0]);
                }
                else if(l<8)
                {
                    lastTemp.push_back(fourTemp[1]);
                }
                else if(l<12)
                {
                    lastTemp.push_back(fourTemp[2]);
                }
                else
                {
                    lastTemp.push_back(fourTemp[3]);
                }
            }

            for(int k=0;k<(fourTemp.size()*4);k++)
            {
                string temp1,temp2,temp3,temp4;
                if(k<4)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;
                }
                else if (k<8)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;
                }
                else if(k<12)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);

                    //break;
                }
                else
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;

                }
            }
        }

    }

    //coping set to the vector

    for(string str : temp_storge_file_names)
    {
        storge_file_names.push_back(str);
    }
}

int Document_Viewer::setFileNum()
{
    string gen=mainWindow->gender,gra=mainWindow->grade,opt=mainWindow->option;


    if(gen=="بنات")
    {
        if(gra=="مرحلة الثانوي")
        {
            if(opt=="اضافي")
            {
                return 0;
            }
            else if(opt=="التعاميم")
            {
                return 1;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
        else if(gra=="مرحلة المتوسط")
        {
            if(opt=="الخطة والتسجيل")
            {
                return 4;
            }
            else if(opt=="التعاميم")
            {
                return 5;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 6;
            }
            else
            {
                return 7;
            }
        }
        else if(gra=="مرحلة الروضة")
        {
            if(opt=="الخطة والتسجيل")
            {
                return 8;
            }
            else if(opt=="التعاميم")
            {
                return 9;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 10;
            }
            else
            {
                return 11;
            }
        }
        else
        {
            if(opt=="الخطة والتسجيل")
            {
                return 12;
            }
            else if(opt=="التعاميم")
            {
                return 13;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 14;
            }
            else
            {
                return 15;
            }
        }
    }
    else if(gen=="بنين")
    {
        if(gra=="مرحلة الثانوي")
        {
            if(opt=="الخطة والتسجيل")
            {
                return 16;
            }
            else if(opt=="التعاميم")
            {
                return 17;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 18;
            }
            else
            {
                return 19;
            }
        }
        else if(gra=="مرحلة المتوسط")
        {
            if(opt=="الخطة والتسجيل")
            {
                return 20;
            }
            else if(opt=="التعاميم")
            {
                return 21;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 22;
            }
            else
            {
                return 23;
            }
        }
        else if(gra=="مرحلة الابتدائي")
        {
            if(opt=="الخطة والتسجيل")
            {
                return 24;
            }
            else if(opt=="التعاميم")
            {
                return 25;
            }
            else if(opt=="الشواهد والتقارير")
            {
                return 26;
            }
            else
            {
                return 27;
            }
        }

    }
    else
    {
        return 0;
    }
}

void Document_Viewer::fileOpener()
{
    storge_files[storge_file_names[setFileNum()]].open(storge_file_names[setFileNum()],ios::app);
}

void Document_Viewer::fileCloser()
{
    storge_files[storge_file_names[setFileNum()]].close();
}

void Document_Viewer::fileNames()
{
    fileOpener();
    string path;
    int tempPlace=0;
    ifstream ifile(storge_file_names[setFileNum()]);
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

        names[setFileNum()][tempPlace].first=path;
        names[setFileNum()][tempPlace].second.first=name;
        names[setFileNum()][tempPlace].second.second=exten;
        tempPlace++;
    }
    fileCloser();
}




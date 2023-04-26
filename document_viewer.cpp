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
#include <QProcess>
#include <QDir>
using namespace std;
extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{

    file.open("C:/Users/Mohamed/Desktop/research/storge.txt",ios::app);

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

    file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    file << file_name.toStdString() <<endl;

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
    if(filesystem::is_empty("C:/Users/Mohamed/Desktop/research/storge.txt"))
    {
        document_preview_btn->setText("لا يوجد ملفات");
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

    string line,emptyString="";
    string path="C:/Users/Mohamed/Desktop/research/storge.txt";
    string eraseLine=currentItem();
    ifstream fin;

    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("C:/Users/Mohamed/Desktop/research/storge.txt");

    while (getline(fin,line))
    {

        //line.replace(line.find(eraseLine),eraseLine.length(),"");

        if(line==eraseLine)
        {
            line.swap(emptyString);
        }

         auto position = line.find(eraseLine);

        if (position != string::npos) {
            line.replace(line.find(eraseLine), eraseLine.length(), "");
        }
        if (!line.empty())
            temp << line << endl;


    }



    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    remove("storge.txt");
    rename("test.txt","storge.txt");



//    string deleteline;
//    string line;

//    ifstream fin;
//    fin.open("example.txt");
//    ofstream temp;
//    temp.open("temp.txt");
//    cout << "Which line do you want to remove? ";
//    cin >> deleteline;



//        while (getline(fin,line))
//    {
//        line.replace(line.find(eraseLine),eraseLine.length(),"");
//        temp << line << endl;

//    }

//    temp.close();
//    fin.close();
//    remove("example.txt");
//    rename("temp.txt","example.txt");

}

void Document_Viewer::fileOpener()
{
    string PATH=names[place%names.size()].first;
    PATH="\""+PATH+"\"";
    const char *c=(PATH).c_str();
    system(c);
}

void Document_Viewer::fileNames()
{

    string path;
    int tempPlace=0;
    ifstream ifile("C:/Users/Mohamed/Desktop/research/storge.txt");
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
}




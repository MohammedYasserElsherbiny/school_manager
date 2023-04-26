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

//loading file demo

void Document_Viewer::loadFile()
{

    file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    file << file_name.toStdString() <<endl;

}

string Document_Viewer::currentItem()
{
    return names[place%names.size()];
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
    if(std::filesystem::is_empty("C:/Users/Mohamed/Desktop/research/storge.txt"))
    {
        document_preview_btn->setText("لا يوجد ملفات");
    }
    else
    {
        document_preview_btn->setText(QString::fromStdString(currentItem()));
    }
}

void Document_Viewer::fileNames()
{

    string item;
    ifstream ifile("C:/Users/Mohamed/Desktop/research/storge.txt");
    while(getline(ifile, item))
    {
        string name;
        bool dotFlag= false;
        int item_size=item.size();
        for(int i=item_size-1;i>=0;i--)
        {
            if(item[i]=='.')
            {
                dotFlag= true;
                continue;
            }

            if(!dotFlag)
            {
                continue;
            }

            if(item[i]=='/')
            {
                break;
            }


            name.push_back(item[i]);
        }

        reverse(name.begin(),name.end());

        names.push_back(name);
    }



}




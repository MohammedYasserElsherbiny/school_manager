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
using namespace std;
extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{
    previous_document_btn = new QPushButton("<");
    next_document_btn = new QPushButton(">");
    document_preview_btn = new QPushButton("ملفات");

    load_file = new QPushButton("Load");
    remove_file = new QPushButton("Remove");
    print_file = new QPushButton("Print");

    QObject::connect(load_file, &QPushButton::clicked, this, & Document_Viewer::loadFile);

//    if(storge_file =="")
//    {
//        storge_file= QFileDialog::getOpenFileName(this,"اختر الملف","C://");
//    }
    file.open("C:/Users/Mohamed/Desktop/research/storge.txt",ios::app);
}

void Document_Viewer::show_window()
{
//    mainWindow->scene->setBackgroundBrush(
//        QBrush(QImage(":/Assets/Images/female_options.jpg").scaledToWidth(mainWindow->width)) // change background based on menu values
//    );

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



    //C:/Users/Mohamed/Desktop/research/storge.txt

    file_name = QFileDialog::getOpenFileName(this,"اختر الملف","C://");

    file << file_name.toStdString() <<endl;



//    if(!file.open(QFile::WriteOnly | QFile::Text))
//    {
//        //file_name= QFileDialog::getOpenFileName(this,"اختر الملف","C://");
//        QTextStream stream(&file);
//        QByteArray QbyteArray_file_name = file_name.toUtf8();
//        file.write(QByteArray(QbyteArray_file_name));
//        stream<<'\n';
//        file.flush();
//    }

//    //QString filename = "Data.txt";
//       // QFile file(filename);
////        if (file.open(QIODevice::ReadWrite)) {

////            stream << "something" << endl;
////        }

////    if (file.open(QIODevice::WriteOnly)) {
////        QTextStream out(&file); out << file_name;
////        file.close();
////      }

//    file.write(file_name.toUtf8());

















//    QFile file( storge_file );
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream( &file );
//        stream << "something" << Qt::endl;
//    }

}


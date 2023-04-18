#include "document_viewer.h"
#include "MainWindow.h"

extern MainWindow * mainWindow;

Document_Viewer::Document_Viewer()
{
    previous_document_btn = new QPushButton("<");
    next_document_btn = new QPushButton(">");
    document_preview_btn = new QPushButton("ملفات");

    load_file = new QPushButton("Load");
    remove_file = new QPushButton("Remove");
    print_file = new QPushButton("Print");
}

void Document_Viewer::show_window()
{
    mainWindow->scene->setBackgroundBrush(
        QBrush(QImage(":/Assets/Images/female_options.jpg").scaledToWidth(mainWindow->width)) // change background based on menu values
    );

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
}

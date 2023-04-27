#include "gradeoptions.h"
#include <MainWindow.h>
#include <gradeselection.h>

extern MainWindow * mainWindow;

GradeOptions::GradeOptions()
{
    planBtn = new QPushButton("");
    planBtn->setText("الخطة والتسجيل");


    circularsBtn = new QPushButton("");
    circularsBtn->setText("التعاميم");


    reportsBtn = new QPushButton("");
    reportsBtn->setText("الشواهد والتقارير");


    additionalBtn = new QPushButton("");
    additionalBtn->setText("اضافي");


    planBtnProxy = mainWindow->scene->addWidget(planBtn);
    planBtnProxy->setPos(mainWindow->width/2 - planBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - planBtnProxy->boundingRect().height()/2-10);



    circularsBtnProxy = mainWindow->scene->addWidget(circularsBtn);
    circularsBtnProxy->setPos(mainWindow->width/2 - circularsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - circularsBtnProxy->boundingRect().height()/2+30);



    reportsBtnProxy = mainWindow->scene->addWidget(reportsBtn);
    reportsBtnProxy->setPos(mainWindow->width/2 - reportsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - reportsBtnProxy->boundingRect().height()/2+70);



    additionalBtnProxy = mainWindow->scene->addWidget(additionalBtn);
    additionalBtnProxy->setPos(mainWindow->width/2 - additionalBtnProxy->boundingRect().width()/2,
                               mainWindow->height/2 - additionalBtnProxy->boundingRect().height()/2+110);

    planBtn->hide();
    circularsBtn->hide();
    reportsBtn->hide();
    additionalBtn->hide();

    QObject::connect(planBtn, &QPushButton::clicked, this, &GradeOptions::setOptionPlan);
    QObject::connect(circularsBtn, &QPushButton::clicked, this, &GradeOptions::setOptionCircular);
    QObject::connect(reportsBtn, &QPushButton::clicked, this, &GradeOptions::setOptionReports);
    QObject::connect(additionalBtn, &QPushButton::clicked, this, &GradeOptions::setOptionAdditional);
}

void GradeOptions::show_window()
{
    if(mainWindow->gender=="male")
    {
        mainWindow->clearScene();
        mainWindow->scene->setBackgroundBrush(
                        QBrush(QImage(":/Assets/Images/male_options.jpg").scaledToWidth(mainWindow->width))
                    );

    }
    else if(mainWindow->gender=="female")
    {
        mainWindow->clearScene();
        mainWindow->scene->setBackgroundBrush(
                        QBrush(QImage(":/Assets/Images/female_options.jpg").scaledToWidth(mainWindow->width))
        );
    }

    planBtn->show();
    circularsBtn->show();
    reportsBtn->show();
    additionalBtn->show();
    mainWindow->backBtn->show();

    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, &GradeOptions::showGradeSelection);
}

void GradeOptions::showGradeSelection()
{
    mainWindow->clearScene();
    mainWindow->grade_selection_window->show_window();
}

void GradeOptions::showDocumentViewer()
{
    mainWindow->clearScene();
    mainWindow->document_viewer->show_window();
}

void GradeOptions::setOptionPlan()
{
    mainWindow->option="Plan";
    showDocumentViewer();
}

void GradeOptions::setOptionCircular()
{
    mainWindow->option="Circular";
    showDocumentViewer();
}

void GradeOptions::setOptionReports()
{
    mainWindow->option="Reports";
    showDocumentViewer();
}

void GradeOptions::setOptionAdditional()
{
    mainWindow->option="Additional";
    showDocumentViewer();
}

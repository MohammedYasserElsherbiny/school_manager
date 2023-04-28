#include "gradeselection.h"
#include<gender_selection.h>
#include <MainWindow.h>

extern MainWindow * mainWindow;

GradeSelection::GradeSelection()
{
    PriBtn = new QPushButton("");
    PriBtn->setText("مرحلة الابتدائي");

    InterBtn = new QPushButton("");
    InterBtn->setText("مرحلة المتوسط");

    HighBtn = new QPushButton("");
    HighBtn->setText("مرحلة الثانوي");

    KinderBtn = new QPushButton("");
    KinderBtn->setText("مرحلة الروضة");


    PriBtnProxy = mainWindow->scene->addWidget(PriBtn);
    PriBtnProxy->setPos(mainWindow->width/2 - PriBtnProxy->boundingRect().width()/2,
                                  mainWindow->height/2 - PriBtnProxy->boundingRect().height()/2-10);

    InterBtnProxy = mainWindow->scene->addWidget(InterBtn);
    InterBtnProxy->setPos(mainWindow->width/2 - InterBtnProxy->boundingRect().width()/2,
                                       mainWindow->height/2 - InterBtnProxy->boundingRect().height()/2+30);

    KinderBtnProxy = mainWindow->scene->addWidget(KinderBtn);
    KinderBtnProxy->setPos(mainWindow->width/2 - KinderBtnProxy->boundingRect().width()/2,
                                       mainWindow->height/2 - KinderBtnProxy->boundingRect().height()/2+110);

    HighBtnProxy = mainWindow->scene->addWidget(HighBtn);
    HighBtnProxy->setPos(mainWindow->width/2 - HighBtnProxy->boundingRect().width()/2,
                                     mainWindow->height/2 - HighBtnProxy->boundingRect().height()/2+70);

    PriBtn->hide();
    InterBtn->hide();
    HighBtn->hide();
    KinderBtn->hide();


    QObject::connect(PriBtn, &QPushButton::clicked, this, &GradeSelection::setGradePri);
    QObject::connect(InterBtn, &QPushButton::clicked, this, &GradeSelection::setGradeInter);
    QObject::connect(HighBtn, &QPushButton::clicked, this, &GradeSelection::setGradeHigh);
    QObject::connect(KinderBtn, &QPushButton::clicked, this, &GradeSelection::setGradeKinder);
}

void GradeSelection::show_window()
{
    if(mainWindow->gender=="بنين")
    {
        mainWindow->clearScene();
        mainWindow->scene->setBackgroundBrush(
                        QBrush(QImage(":/Assets/Images/male_grade.jpg").scaledToWidth(mainWindow->width))
        );

    }
    else if(mainWindow->gender=="بنات")
    {
        mainWindow->clearScene();
        mainWindow->scene->setBackgroundBrush(
            QBrush(QImage(":/Assets/Images/female_grade.jpg").scaledToWidth(mainWindow->width))
        );

        KinderBtn->show();
    }

    PriBtn->show();
    InterBtn->show();
    HighBtn->show();
    mainWindow->backBtn->show();

    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, & GradeSelection::showGenderSelectionWindow);
}

void GradeSelection::showGenderSelectionWindow()
{
    mainWindow->clearScene();
    mainWindow->gender_selection_window->show_window();
}

void GradeSelection::showGradeOptions()
{
    mainWindow->clearScene();
    mainWindow->grade_options_window->show_window();
}

void GradeSelection::setGradePri()
{
    mainWindow->grade= "مرحلة الابتدائي";
    showGradeOptions();
}

void GradeSelection::setGradeInter()
{
    mainWindow->grade= "مرحلة المتوسط";
    showGradeOptions();
}

void GradeSelection::setGradeHigh()
{
    mainWindow->grade="مرحلة الثانوي";
    showGradeOptions();
}

void GradeSelection::setGradeKinder()
{
    mainWindow->grade="مرحلة الروضة";
    showGradeOptions();
}

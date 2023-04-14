#include "gender_selection.h"
#include <male_grade.h>
#include <female_grade.h>
#include <MainWindow.h>

extern MainWindow * mainWindow;

Gender_Selection::Gender_Selection()
{
    maleBtn = new QPushButton("");
    maleBtn->setText("Male");

    femaleBtn = new QPushButton("");
    femaleBtn->setText("female");

    QObject::connect(maleBtn, &QPushButton::clicked, this, &Gender_Selection::showMaleGradeWindow);
    QObject::connect(femaleBtn, &QPushButton::clicked, this, &Gender_Selection::showFemaleGradeWindow);
}

void Gender_Selection::show_window()
{
    mainWindow->scene->setBackgroundBrush(
        QBrush(QImage(":/Assets/Images/gender.jpg").scaledToWidth(mainWindow->width))
    );

    maleBtnProxy = mainWindow->scene->addWidget(maleBtn);
    maleBtnProxy->setPos(mainWindow->width/2 + 30,
                         mainWindow->height/2 - maleBtnProxy->boundingRect().height()/2+30);

    femaleBtnProxy = mainWindow->scene->addWidget(femaleBtn);
    femaleBtnProxy->setPos(mainWindow->width/2 - femaleBtnProxy->boundingRect().width() - 20,
                           mainWindow->height/2 - femaleBtnProxy->boundingRect().height()/2+30);
}

void Gender_Selection::showMaleGradeWindow()
{
    mainWindow->clearScene();
    maleGrade = new male_grade();
}

void Gender_Selection::showFemaleGradeWindow()
{
    mainWindow->clearScene();
    mainWindow->female_grade_window->show_window();
}

void Gender_Selection::showMainWindow()
{
    mainWindow->clearScene();
    mainWindow->show_window();
}

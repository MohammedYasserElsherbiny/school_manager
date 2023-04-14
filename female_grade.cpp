#include "female_grade.h"
#include <MainWindow.h>
#include <gender_selection.h>

extern MainWindow * mainWindow;

female_grade::female_grade()
{
    femalePrimaryBtn = new QPushButton("");
    femalePrimaryBtn->setText("مرحلة الروضة");

    femaleIntermediateBtn = new QPushButton("");
    femaleIntermediateBtn->setText("مرحلة الابتدائي");

    femaleHighschoolBtn = new QPushButton("");
    femaleHighschoolBtn->setText("مرحلة المتوسط");

    femaleKindergartenBtn = new QPushButton("");
    femaleKindergartenBtn->setText("مرحلة الثانوي");

    backBtn = new QPushButton("");
    backBtn->setText("مرحلة الثانوي");

    QObject::connect(femalePrimaryBtn, &QPushButton::clicked, this, &female_grade::showFemaleOptionsWindow);
    QObject::connect(femaleIntermediateBtn, &QPushButton::clicked, this, &female_grade::showFemaleOptionsWindow);
    QObject::connect(femaleHighschoolBtn, &QPushButton::clicked, this, &female_grade::showFemaleOptionsWindow);
    QObject::connect(femaleKindergartenBtn, &QPushButton::clicked, this, &female_grade::showFemaleOptionsWindow);
}

void female_grade::show_window()
{
    mainWindow->scene->setBackgroundBrush(
        QBrush(QImage(":/Assets/Images/female_grade.jpg").scaledToWidth(mainWindow->width))
    );

    femalePrimaryBtnProxy = mainWindow->scene->addWidget(femalePrimaryBtn);
    femalePrimaryBtnProxy->setPos(mainWindow->width/2 - femalePrimaryBtnProxy->boundingRect().width()/2,
                                  mainWindow->height/2 - femalePrimaryBtnProxy->boundingRect().height()/2-10);

    femaleIntermediateBtnProxy = mainWindow->scene->addWidget(femaleIntermediateBtn);
    femaleIntermediateBtnProxy->setPos(mainWindow->width/2 - femaleIntermediateBtnProxy->boundingRect().width()/2,
                                       mainWindow->height/2 - femaleIntermediateBtnProxy->boundingRect().height()/2+30);

    femaleKindergartenBtnProxy = mainWindow->scene->addWidget(femaleKindergartenBtn);
    femaleKindergartenBtnProxy->setPos(mainWindow->width/2 - femaleKindergartenBtnProxy->boundingRect().width()/2,
                                       mainWindow->height/2 - femaleKindergartenBtnProxy->boundingRect().height()/2+110);

    femaleHighschoolBtnProxy = mainWindow->scene->addWidget(femaleHighschoolBtn);
    femaleHighschoolBtnProxy->setPos(mainWindow->width/2 - femaleHighschoolBtnProxy->boundingRect().width()/2,
                                     mainWindow->height/2 - femaleHighschoolBtnProxy->boundingRect().height()/2+70);

    backBtnProxy = mainWindow->scene->addWidget(backBtn);
    backBtnProxy->setPos(mainWindow->width/2 - backBtnProxy->boundingRect().width()/2,
                         mainWindow->height/2 - backBtnProxy->boundingRect().height()/2+110);

}

void female_grade:: showFemaleOptionsWindow()
{
    mainWindow->clearScene();
    mainWindow->female_options_window->show_window();
}

void female_grade::showGenderSelectionWindow()
{
    mainWindow->clearScene ();
    mainWindow->gender_selection_window->show_window();
}

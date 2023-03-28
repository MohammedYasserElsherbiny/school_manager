#include "male_grade.h"
#include <MainWindow.h>


extern MainWindow * mainWindow;

male_grade::male_grade()
{

    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/male_grade.jpg").scaledToWidth(mainWindow->width))
                );

    primaryBtn = new QPushButton("");
    primaryBtn->setText("مرحلة الابتدائي");
    primaryBtnProxy = mainWindow->scene->addWidget(primaryBtn);
    primaryBtnProxy->setPos(mainWindow->width/2 - primaryBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - primaryBtnProxy->boundingRect().height()/2-10);

    IntermediateBtn = new QPushButton("");
    IntermediateBtn->setText("مرحلة المتوسط");
    IntermediateBtnProxy = mainWindow->scene->addWidget(IntermediateBtn);
    IntermediateBtnProxy->setPos(mainWindow->width/2 - IntermediateBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - IntermediateBtnProxy->boundingRect().height()/2+30);

    highschoolBtn = new QPushButton("");
    highschoolBtn->setText("مرحلة الثانوي");
    highschoolBtnProxy = mainWindow->scene->addWidget(highschoolBtn);
    highschoolBtnProxy->setPos(mainWindow->width/2 - highschoolBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - highschoolBtnProxy->boundingRect().height()/2+70);

    QObject::connect(primaryBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);
    QObject::connect(IntermediateBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);
    QObject::connect(highschoolBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);

}


void male_grade:: showMaleOptionsWindow()
{
    mainWindow->clearScene();
    maleOptions = new male_options();
}
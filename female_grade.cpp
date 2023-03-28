#include "female_grade.h"
#include <MainWindow.h>

extern MainWindow * mainWindow;

female_grade::female_grade()
{

    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/female_grade.jpg").scaledToWidth(mainWindow->width))
                );

    femalePrimaryBtn = new QPushButton("");
    femalePrimaryBtn->setText("مرحلة الروضة");
    femalePrimaryBtnProxy = mainWindow->scene->addWidget(femalePrimaryBtn);
    femalePrimaryBtnProxy->setPos(mainWindow->width/2 - femalePrimaryBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femalePrimaryBtnProxy->boundingRect().height()/2-10);

    femaleIntermediateBtn = new QPushButton("");
    femaleIntermediateBtn->setText("مرحلة الابتدائي");
    femaleIntermediateBtnProxy = mainWindow->scene->addWidget(femaleIntermediateBtn);
    femaleIntermediateBtnProxy->setPos(mainWindow->width/2 - femaleIntermediateBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleIntermediateBtnProxy->boundingRect().height()/2+30);

    femaleHighschoolBtn = new QPushButton("");
    femaleHighschoolBtn->setText("مرحلة المتوسط");
    femaleHighschoolBtnProxy = mainWindow->scene->addWidget(femaleHighschoolBtn);
    femaleHighschoolBtnProxy->setPos(mainWindow->width/2 - femaleHighschoolBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleHighschoolBtnProxy->boundingRect().height()/2+70);

    femaleKindergartenBtn = new QPushButton("");
    femaleKindergartenBtn->setText("مرحلة الثانوي");
    femaleKindergartenBtnProxy = mainWindow->scene->addWidget(femaleKindergartenBtn);
    femaleKindergartenBtnProxy->setPos(mainWindow->width/2 - femaleKindergartenBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleKindergartenBtnProxy->boundingRect().height()/2+110);
}

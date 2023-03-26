#include "gender_selection.h"
#include <MainWindow.h>

extern MainWindow * mainWindow;

Gender_Selection::Gender_Selection()
{
    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/gender.jpg").scaledToWidth(mainWindow->width))
                );

    maleBtn = new QPushButton("");
    maleBtn->setText("Male");
    maleBtnProxy = mainWindow->scene->addWidget(maleBtn);
    maleBtnProxy->setPos(mainWindow->width/2 + 20,
                          mainWindow->height/2 - maleBtnProxy->boundingRect().height()/2);

    femaleBtn = new QPushButton("");
    femaleBtn->setText("female");
    femaleBtnProxy = mainWindow->scene->addWidget(femaleBtn);
    femaleBtnProxy->setPos(mainWindow->width/2 - femaleBtnProxy->boundingRect().width() - 20,
                          mainWindow->height/2 - femaleBtnProxy->boundingRect().height()/2);
}

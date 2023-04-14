#include "male_options.h"
#include <MainWindow.h>

extern MainWindow * mainWindow;

male_options::male_options()
{



    planBtn = new QPushButton("");
    planBtn->setText("الخطة والتسجيل");


    circularsBtn = new QPushButton("");
    circularsBtn->setText("التعاميم");


    reportsBtn = new QPushButton("");
    reportsBtn->setText("الشواهد والتقارير");


    additionalBtn = new QPushButton("");
    additionalBtn->setText("اضافي");

}

void male_options::show_window()
{
    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/male_options.jpg").scaledToWidth(mainWindow->width))
                );



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
}

void male_options::showMaleGradeWindow()
{
    mainWindow->clearScene();
    mainWindow->male_options_window->show_window();
}

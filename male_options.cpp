#include "male_options.h"
#include <MainWindow.h>

extern MainWindow * mainWindow;

male_options::male_options()
{

    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/male_options.jpg").scaledToWidth(mainWindow->width))
                );

    planBtn = new QPushButton("");
    planBtn->setText("الخطة والتسجيل");
    planBtnProxy = mainWindow->scene->addWidget(planBtn);
    planBtnProxy->setPos(mainWindow->width/2 - planBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - planBtnProxy->boundingRect().height()/2-10);

    circularsBtn = new QPushButton("");
    circularsBtn->setText("التعاميم");
    circularsBtnProxy = mainWindow->scene->addWidget(circularsBtn);
    circularsBtnProxy->setPos(mainWindow->width/2 - circularsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - circularsBtnProxy->boundingRect().height()/2+30);

    reportsBtn = new QPushButton("");
    reportsBtn->setText("الشواهد والتقارير");
    reportsBtnProxy = mainWindow->scene->addWidget(reportsBtn);
    reportsBtnProxy->setPos(mainWindow->width/2 - reportsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - reportsBtnProxy->boundingRect().height()/2+70);

    additionalBtn = new QPushButton("");
    additionalBtn->setText("اضافي");
    additionalBtnProxy = mainWindow->scene->addWidget(additionalBtn);
    additionalBtnProxy->setPos(mainWindow->width/2 - additionalBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - additionalBtnProxy->boundingRect().height()/2+110);
}

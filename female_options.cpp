#include "female_options.h"
#include <MainWindow.h>

extern MainWindow * mainWindow;

female_options::female_options()
{

    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/female_options.jpg").scaledToWidth(mainWindow->width))
                );

    femalePlanBtn = new QPushButton("");
    femalePlanBtn->setText("الخطة والتسجيل");
    femalePlanBtnProxy = mainWindow->scene->addWidget(femalePlanBtn);
    femalePlanBtnProxy->setPos(mainWindow->width/2 - femalePlanBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femalePlanBtnProxy->boundingRect().height()/2-10);

    femaleCircularsBtn = new QPushButton("");
    femaleCircularsBtn->setText("التعاميم");
    femaleCircularsBtnProxy = mainWindow->scene->addWidget(femaleCircularsBtn);
    femaleCircularsBtnProxy->setPos(mainWindow->width/2 - femaleCircularsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleCircularsBtnProxy->boundingRect().height()/2+30);

    femaleReportsBtn = new QPushButton("");
    femaleReportsBtn->setText("الشواهد والتقارير");
    femaleReportsBtnProxy = mainWindow->scene->addWidget(femaleReportsBtn);
    femaleReportsBtnProxy->setPos(mainWindow->width/2 - femaleReportsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleReportsBtnProxy->boundingRect().height()/2+70);

    femaleAdditionalBtn = new QPushButton("");
    femaleAdditionalBtn->setText("اضافي");
    femaleAdditionalBtnProxy = mainWindow->scene->addWidget(femaleAdditionalBtn);
    femaleAdditionalBtnProxy->setPos(mainWindow->width/2 - femaleAdditionalBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleAdditionalBtnProxy->boundingRect().height()/2+110);
}

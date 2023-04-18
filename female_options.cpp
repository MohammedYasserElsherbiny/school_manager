#include "female_options.h"
#include <MainWindow.h>
#include <female_grade.h>

extern MainWindow * mainWindow;

female_options::female_options()
{



    femalePlanBtn = new QPushButton("");
    femalePlanBtn->setText("الخطة والتسجيل");


    femaleCircularsBtn = new QPushButton("");
    femaleCircularsBtn->setText("التعاميم");


    femaleReportsBtn = new QPushButton("");
    femaleReportsBtn->setText("الشواهد والتقارير");


    femaleAdditionalBtn = new QPushButton("");
    femaleAdditionalBtn->setText("اضافي");


    femalePlanBtnProxy = mainWindow->scene->addWidget(femalePlanBtn);
    femalePlanBtnProxy->setPos(mainWindow->width/2 - femalePlanBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femalePlanBtnProxy->boundingRect().height()/2-10);



    femaleCircularsBtnProxy = mainWindow->scene->addWidget(femaleCircularsBtn);
    femaleCircularsBtnProxy->setPos(mainWindow->width/2 - femaleCircularsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleCircularsBtnProxy->boundingRect().height()/2+30);



    femaleReportsBtnProxy = mainWindow->scene->addWidget(femaleReportsBtn);
    femaleReportsBtnProxy->setPos(mainWindow->width/2 - femaleReportsBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - femaleReportsBtnProxy->boundingRect().height()/2+70);



    femaleAdditionalBtnProxy = mainWindow->scene->addWidget(femaleAdditionalBtn);
    femaleAdditionalBtnProxy->setPos(mainWindow->width/2 - femaleAdditionalBtnProxy->boundingRect().width()/2,
                                     mainWindow->height/2 - femaleAdditionalBtnProxy->boundingRect().height()/2+110);


    femalePlanBtnProxy->hide();
    femaleCircularsBtnProxy->hide();
    femaleReportsBtnProxy->hide();
    femaleAdditionalBtnProxy->hide();


    //QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, & female_options::showFemaleGradeWindow);


}

void female_options::show_window()
{
    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/female_options.jpg").scaledToWidth(mainWindow->width))
    );

    femalePlanBtnProxy->show();
    femaleCircularsBtnProxy->show();
    femaleReportsBtnProxy->show();
    femaleAdditionalBtnProxy->show();


    mainWindow->backBtn->show();



    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, & female_options::showFemaleGradeWindow);

}

void female_options::showFemaleGradeWindow()
{
    mainWindow->clearScene();
    mainWindow->female_grade_window->show_window();
}

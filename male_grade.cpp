#include <MainWindow.h>


extern MainWindow * mainWindow;

male_grade::male_grade()
{



    primaryBtn = new QPushButton("");
    primaryBtn->setText("مرحلة الابتدائي");


    IntermediateBtn = new QPushButton("");
    IntermediateBtn->setText("مرحلة المتوسط");


    highschoolBtn = new QPushButton("");
    highschoolBtn->setText("مرحلة الثانوي");


    primaryBtnProxy = mainWindow->scene->addWidget(primaryBtn);
    primaryBtnProxy->setPos(mainWindow->width/2 - primaryBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - primaryBtnProxy->boundingRect().height()/2-10);


    IntermediateBtnProxy = mainWindow->scene->addWidget(IntermediateBtn);
    IntermediateBtnProxy->setPos(mainWindow->width/2 - IntermediateBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - IntermediateBtnProxy->boundingRect().height()/2+30);


    highschoolBtnProxy = mainWindow->scene->addWidget(highschoolBtn);
    highschoolBtnProxy->setPos(mainWindow->width/2 - highschoolBtnProxy->boundingRect().width()/2,
                          mainWindow->height/2 - highschoolBtnProxy->boundingRect().height()/2+70);

    primaryBtn->hide();
    IntermediateBtn->hide();
    highschoolBtn->hide();


    QObject::connect(primaryBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);
    QObject::connect(IntermediateBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);
    QObject::connect(highschoolBtn, &QPushButton::clicked, this, &male_grade::showMaleOptionsWindow);

}

void male_grade::show_window()
{
    mainWindow->scene->setBackgroundBrush(
                    QBrush(QImage(":/Assets/Images/male_grade.jpg").scaledToWidth(mainWindow->width))
    );

    primaryBtn->show();
    IntermediateBtn->show();
    highschoolBtn->show();
    mainWindow->backBtn->show();

    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, &male_grade::showGenderSelectionWindow);

}


void male_grade:: showMaleOptionsWindow()
{
    mainWindow->clearScene();
    mainWindow->male_options_window->show_window();
}

void male_grade::showGenderSelectionWindow()
{
   mainWindow->clearScene();
   mainWindow->gender_selection_window->show_window();
}




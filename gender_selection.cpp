#include <MainWindow.h>

extern MainWindow * mainWindow;

Gender_Selection::Gender_Selection()
{


    maleBtn = new QPushButton("");
    maleBtn->setText("Male");

    femaleBtn = new QPushButton("");
    femaleBtn->setText("female");



    maleBtnProxy = mainWindow->scene->addWidget(maleBtn);
    maleBtnProxy->setPos(mainWindow->width/2 + 30,
                         mainWindow->height/2 - maleBtnProxy->boundingRect().height()/2+30);

    femaleBtnProxy = mainWindow->scene->addWidget(femaleBtn);
    femaleBtnProxy->setPos(mainWindow->width/2 - femaleBtnProxy->boundingRect().width() - 20,
                           mainWindow->height/2 - femaleBtnProxy->boundingRect().height()/2+30);


    femaleBtn->hide();
    maleBtn->hide();



    QObject::connect(maleBtn, &QPushButton::clicked, this, &Gender_Selection::showMaleGradeWindow);
    QObject::connect(femaleBtn, &QPushButton::clicked, this, &Gender_Selection::showFemaleGradeWindow);

}

void Gender_Selection::show_window()
{
    mainWindow->scene->setBackgroundBrush(
        QBrush(QImage(":/Assets/Images/gender.jpg").scaledToWidth(mainWindow->width))
    );

    maleBtn->show();
    femaleBtn->show();
    mainWindow->backBtn->show();

    QObject::connect(mainWindow->backBtn, &QPushButton::clicked, this, &Gender_Selection::showMainWindow);
}

void Gender_Selection::showMaleGradeWindow()
{
    mainWindow->gender="male";
    mainWindow->clearScene();
    mainWindow->grade_selection_window->show_window();
}

void Gender_Selection::showFemaleGradeWindow()
{

    mainWindow->gender="female";
    mainWindow->clearScene();
    mainWindow->grade_selection_window->show_window();
}

void Gender_Selection::showMainWindow()
{

    mainWindow->clearScene();
    mainWindow->show_window();
}

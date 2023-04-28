#include "MainWindow.h"

MainWindow::MainWindow()
{
    // Setup global Scene
    scene = new QGraphicsScene();

    // Get Display Resolution
    screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    width = 600; // screenGeometry.width()
    height = 400; // screenGeometry.height()

    // Set scene properties
    scene->setSceneRect(0,0, width, height); // TODO: Improve screen size



    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);





    // Btn Demo
    startBtn = new QPushButton();
    startBtn->setText("Start");

    backBtn = new QPushButton();
    backBtn->setText("Back");




    startBtnProxy = scene->addWidget(startBtn);
    startBtnProxy->setPos(width/2 - startBtnProxy->boundingRect().width()/2,
                          height - startBtnProxy->boundingRect().height() - 20);

    backBtnProxy = scene->addWidget(backBtn);
    backBtnProxy->setPos(width/8 - backBtnProxy->boundingRect().width()+50,
                          height - backBtnProxy->boundingRect().height() - 350);

    backBtn->hide();


    // create on click event listeners
    QObject::connect(startBtn, &QPushButton::clicked, this, &MainWindow::showGenderSelectionWindow);
}

void MainWindow::initWindows()
{
    // Init Windows
    gender_selection_window = new Gender_Selection();
    document_viewer = new Document_Viewer();
    grade_options_window = new GradeOptions();
    grade_selection_window = new GradeSelection();
}

void MainWindow::clearScene()
{
    foreach (QGraphicsItem *item, scene->items()) {
        if(item != backBtnProxy)
        item->hide();
            //scene->removeItem(item);
    }
}

void MainWindow::show_window()
{


    scene->setBackgroundBrush(QBrush(QImage(":/Assets/Images/start.jpg").scaledToWidth(width)));

    startBtn->show();

    backBtn->hide();

//    backBtnProxy = scene->addWidget(backBtn);
//    backBtnProxy->setPos(width/8 - backBtnProxy->boundingRect().width()+50,
//                          height - backBtnProxy->boundingRect().height() - 350);
}

void MainWindow::showGenderSelectionWindow()
{
    clearScene();

    gender_selection_window->show_window();
    //document_viewer->show_window();
}



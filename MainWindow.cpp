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
    scene->setBackgroundBrush(QBrush(QImage(":/Assets/Images/start.jpg").scaledToWidth(width)));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Btn Demo
    startBtn = new QPushButton();
    startBtn->setText("Start");
    startBtnProxy = scene->addWidget(startBtn);
    startBtnProxy->setPos(width/2 - startBtnProxy->boundingRect().width()/2,
                          height - startBtnProxy->boundingRect().height() - 20);

    // create on click event listeners
    QObject::connect(startBtn, &QPushButton::clicked, this, &MainWindow::showGenderSelectionWindow);

    //QObject::connect(maleBtn, &QPushButton::clicked, this, &Gender_Selection::showMaleGradeWindow);

    show();
}

void MainWindow::clearScene()
{
    foreach (QGraphicsItem *item, scene->items()) {
        scene->removeItem(item);
    }
}

void MainWindow::showGenderSelectionWindow()
{
    clearScene();

    gender_selection_window = new Gender_Selection();
}



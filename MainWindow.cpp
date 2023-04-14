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

    // Init Windows
    gender_selection_window = new Gender_Selection();
    female_grade_window = new female_grade();
    male_grade_window = new male_grade();
    female_options_window = new female_options();
    male_options_window = new male_options();
    document_viewer = new Document_Viewer();

    // create on click event listeners
    QObject::connect(startBtn, &QPushButton::clicked, this, &MainWindow::showGenderSelectionWindow);
}

void MainWindow::clearScene()
{
    foreach (QGraphicsItem *item, scene->items()) {
        scene->removeItem(item);
    }
}

void MainWindow::show_window()
{
    startBtnProxy = scene->addWidget(startBtn);
    startBtnProxy->setPos(width/2 - startBtnProxy->boundingRect().width()/2,
                          height - startBtnProxy->boundingRect().height() - 20);
}

void MainWindow::showGenderSelectionWindow()
{
    clearScene();

//    gender_selection_window->show_window();
    document_viewer->show_window();
}



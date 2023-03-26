#include "MainWindow.h"

MainWindow::MainWindow()
{
    // Setup global Scene
    scene = new QGraphicsScene();

    // Get Display Resolution
    screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    height = 400; // screenGeometry.height()
    width = 600; // screenGeometry.width()

    // Set scene properties
    scene->setSceneRect(0,0, width, height); // TODO: Improve screen size
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToWidth(width))); // TODO: Setup Storage and add background image
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Btn Demo
    firstBtn = new QPushButton();
    firstBtn->setText("First");
    firstBtnProxy = scene->addWidget(firstBtn);
    firstBtnProxy->setPos(width/2 - firstBtnProxy->boundingRect().width()/2, 20);

//    secondBtn = new QPushButton("");
//    secondBtn->setText("Second");
//    secondBtnProxy = scene->addWidget(secondBtn);
//    secondBtnProxy->setPos(firstBtnProxy->boundingRect().width() + 40, 20);

//    ThirdBtn = new QPushButton("");
//    ThirdBtn->setText("Third");
//    ThirdBtnProxy = scene->addWidget(ThirdBtn);
//    ThirdBtnProxy->setPos(secondBtnProxy->boundingRect().width() + firstBtnProxy->boundingRect().width() + 60, 40);



    // create on click event listeners
//    QObject::connect(firstBtn, &QPushButton::clicked, this, &Game::quitGame);
//    QObject::connect(secondBtn, &QPushButton::clicked, this, &Game::quitGame);


    show();
}

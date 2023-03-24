#include "panel.h"

Panel::Panel()
{
    // Setup global Scene
    scene = new QGraphicsScene();

    // Get Display Resolution
    screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    height = 600; // screenGeometry.height()
    width = 400; // screenGeometry.width()

    // Set scene properties
    scene->setSceneRect(0,0,600,400); // TODO: Improve screen size
//    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToWidth(width))); // TODO: Setup Storage and add background image
    setScene(scene);
//    setWindowState(Qt::WindowFullScreen);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Btn Demo
    firstBtn = new QPushButton("");
    firstBtn->setText("First");
    firstBtnProxy = scene->addWidget(firstBtn);
    firstBtnProxy->setPos(firstBtnProxy->boundingRect().width()+30, 20);

    secondBtn = new QPushButton("");
    secondBtn->setText("Second");
    secondBtnProxy = scene->addWidget(secondBtn);
    secondBtnProxy->setPos(20, 20);

    // create on click event listeners
//    QObject::connect(firstBtn, &QPushButton::clicked, this, &Game::quitGame);
//    QObject::connect(secondBtn, &QPushButton::clicked, this, &Game::quitGame);

    show();
}

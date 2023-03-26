#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class MainWindow : public QGraphicsView
{
public:
    MainWindow();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;

private:
    QPushButton *firstBtn, *secondBtn, *ThirdBtn;
    QGraphicsProxyWidget *firstBtnProxy, *secondBtnProxy, *ThirdBtnProxy;
};

#endif // MAINWINDOW_H

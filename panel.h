#ifndef PANEL_H
#define PANEL_H

#include <QGraphicsView>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class Panel : public QGraphicsView
{
public:
    Panel();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;

private:
    QPushButton *firstBtn, *secondBtn;
    QGraphicsProxyWidget *firstBtnProxy, *secondBtnProxy;
};

#endif // PANEL_H

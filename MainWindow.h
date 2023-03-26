#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QBrush>
#include <QImage>
#include <gender_selection.h>

class MainWindow : public QGraphicsView
{
public:
    MainWindow();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;
    Gender_Selection *gender_selection_window;

private:
    void clearScene();
    void showGenderSelectionWindow();
    QPushButton *startBtn;
    QGraphicsProxyWidget *startBtnProxy;
};

#endif // MAINWINDOW_H

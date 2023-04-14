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
#include <male_grade.h>
#include <female_grade.h>
#include <female_options.h>
#include <male_options.h>
#include <document_viewer.h>

class MainWindow : public QGraphicsView
{
public:
    MainWindow();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;

    // Windows declarations
    Gender_Selection *gender_selection_window;
    male_grade *male_grade_window;
    female_grade *female_grade_window;
    male_options *male_options_window;
    female_options *female_options_window;
    Document_Viewer *document_viewer;

    // Window functions
    void clearScene();
    void show_window();

private:
    void showGenderSelectionWindow();
    QPushButton *startBtn;
    QGraphicsProxyWidget *startBtnProxy;
};

#endif // MAINWINDOW_H

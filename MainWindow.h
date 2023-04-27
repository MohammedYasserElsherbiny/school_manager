#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QFile>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QBrush>
#include <QImage>
#include <gender_selection.h>
#include <document_viewer.h>
#include <gradeselection.h>
#include <gradeoptions.h>

class MainWindow : public QGraphicsView
{
public:
    MainWindow();
    void initWindows ();
    int width, height;
    QGraphicsScene *scene;
    QScreen *screen;

    QPushButton *backBtn;
    QGraphicsProxyWidget *backBtnProxy;

    // Windows declarations
    Gender_Selection *gender_selection_window;
    Document_Viewer *document_viewer;
    GradeSelection *grade_selection_window;
    GradeOptions *grade_options_window;



    QString gender,grade,option;

    // Window functions
    void clearScene();
    void show_window();

private:
    void showGenderSelectionWindow();
    QPushButton *startBtn;
    QGraphicsProxyWidget *startBtnProxy;
};

#endif // MAINWINDOW_H

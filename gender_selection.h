#ifndef GENDER_SELECTION_H
#define GENDER_SELECTION_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>


class Gender_Selection : public QGraphicsView
{
public:
    Gender_Selection();
    void show_window();

private:
    QPushButton *maleBtn, *femaleBtn;
    QGraphicsProxyWidget *maleBtnProxy, *femaleBtnProxy;
    void showMaleGradeWindow();
    void showFemaleGradeWindow();
    void showMainWindow();
};

#endif // GENDER_SELECTION_H

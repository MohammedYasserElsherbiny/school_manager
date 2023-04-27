#ifndef GRADESELECTION_H
#define GRADESELECTION_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
//#include <_options.h>


class GradeSelection : public QGraphicsView
{
public:
    GradeSelection();
    void show_window();

private:
    QPushButton *PriBtn, *InterBtn, *HighBtn, *KinderBtn, *backBtn;
    QGraphicsProxyWidget *PriBtnProxy, *InterBtnProxy, *HighBtnProxy, *KinderBtnProxy, *backBtnProxy;

    QPushButton *malePriBtn, *maleInterBtn, *maleHighBtn;
    QGraphicsProxyWidget *malePriBtnProxy, *maleInterBtnProxy, *maleHighProxy;

    void showGenderSelectionWindow ();
    void showGradeOptions ();
    void setGradePri ();
    void setGradeInter ();
    void setGradeHigh ();
    void setGradeKinder ();
};

#endif // GRADESELECTION_H

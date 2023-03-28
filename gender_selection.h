#ifndef GENDER_SELECTION_H
#define GENDER_SELECTION_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <male_grade.h>
#include <female_grade.h>

class Gender_Selection : public QGraphicsView
{
public:
    Gender_Selection();

private:
    QPushButton *maleBtn, *femaleBtn;
    male_grade *maleGrade;
    female_grade *femaleGrade;
    QGraphicsProxyWidget *maleBtnProxy, *femaleBtnProxy;
    void showMaleGradeWindow();
    void showFemaleGradeWindow();
};

#endif // GENDER_SELECTION_H

#ifndef FEMALE_GRADE_H
#define FEMALE_GRADE_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <female_options.h>


class female_grade : public QGraphicsView
{
public:
    female_grade();
    void show_window();

private:
    QPushButton *femalePrimaryBtn, *femaleIntermediateBtn, *femaleHighschoolBtn, *femaleKindergartenBtn, *backBtn;
    QGraphicsProxyWidget *femalePrimaryBtnProxy, *femaleIntermediateBtnProxy, *femaleHighschoolBtnProxy, *femaleKindergartenBtnProxy, *backBtnProxy;
    female_options *femaleOptions;
    void showFemaleOptionsWindow ();
    void showGenderSelectionWindow ();
};

#endif // FEMALE_GRADE_H

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

private:
    QPushButton *femalePrimaryBtn, *femaleIntermediateBtn, *femaleHighschoolBtn, *femaleKindergartenBtn;
    QGraphicsProxyWidget *femalePrimaryBtnProxy, *femaleIntermediateBtnProxy, *femaleHighschoolBtnProxy, *femaleKindergartenBtnProxy;
    female_options *femaleOptions;
    void showFemaleOptionsWindow ();
};

#endif // FEMALE_GRADE_H

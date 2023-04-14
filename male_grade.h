#ifndef MALE_GRADE_H
#define MALE_GRADE_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <male_options.h>


class male_grade : public QGraphicsView
{
public:
    male_grade();
    void show_window();
private:
    QPushButton *primaryBtn, *IntermediateBtn, *highschoolBtn;
    QGraphicsProxyWidget *primaryBtnProxy, *IntermediateBtnProxy, *highschoolBtnProxy;
    male_options *maleOptions;
    void showMaleOptionsWindow ();
    void showGenderSelectionWindow ();
};

#endif // MALE_GRADE_H

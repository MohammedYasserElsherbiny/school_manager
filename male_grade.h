#ifndef MALE_GRADE_H
#define MALE_GRADE_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>


class male_grade : public QGraphicsView
{
public:
    male_grade();

private:
    QPushButton *primaryBtn, *IntermediateBtn, *highschoolBtn;
    QGraphicsProxyWidget *primaryBtnProxy, *IntermediateBtnProxy, *highschoolBtnProxy;
};

#endif // MALE_GRADE_H

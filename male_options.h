#ifndef MALE_OPTIONS_H
#define MALE_OPTIONS_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class male_options : public QGraphicsView
{
public:
    male_options();
    void show_window();
private:
    QPushButton *planBtn, *circularsBtn, *reportsBtn, *additionalBtn;
    QGraphicsProxyWidget *planBtnProxy, *circularsBtnProxy, *reportsBtnProxy, *additionalBtnProxy;
    void showMaleGradeWindow ();
};

#endif // MALE_OPTIONS_H

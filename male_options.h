#ifndef MALE_OPTIONS_H
#define MALE_OPTIONS_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class male_options : public QGraphicsView
{
public:
    male_options();

private:
    QPushButton *planBtn, *circularsBtn, *reportsBtn, *additionalBtn;
    QGraphicsProxyWidget *planBtnProxy, *circularsBtnProxy, *reportsBtnProxy, *additionalBtnProxy;
};

#endif // MALE_OPTIONS_H

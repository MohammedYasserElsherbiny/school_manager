#ifndef GENDER_SELECTION_H
#define GENDER_SELECTION_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class Gender_Selection : public QGraphicsView
{
public:
    Gender_Selection();

private:
    QPushButton *maleBtn, *femaleBtn;
    QGraphicsProxyWidget *maleBtnProxy, *femaleBtnProxy;
};

#endif // GENDER_SELECTION_H

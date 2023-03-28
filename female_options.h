#ifndef FEMALE_OPTIONS_H
#define FEMALE_OPTIONS_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class female_options
{
public:
    female_options();

private:
    QPushButton *femalePlanBtn, *femaleCircularsBtn, *femaleReportsBtn, *femaleAdditionalBtn;
    QGraphicsProxyWidget *femalePlanBtnProxy, *femaleCircularsBtnProxy, *femaleReportsBtnProxy, *femaleAdditionalBtnProxy;
};

#endif // FEMALE_OPTIONS_H

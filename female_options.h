#ifndef FEMALE_OPTIONS_H
#define FEMALE_OPTIONS_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class female_options : public QGraphicsView
{
public:
    female_options();
    void show_window();
private:
    QPushButton *femalePlanBtn, *femaleCircularsBtn, *femaleReportsBtn, *femaleAdditionalBtn, *backBtn;
    QGraphicsProxyWidget *femalePlanBtnProxy, *femaleCircularsBtnProxy, *femaleReportsBtnProxy, *femaleAdditionalBtnProxy, *backBtnProxy;
    void showFemaleGradeWindow ();
};

#endif // FEMALE_OPTIONS_H

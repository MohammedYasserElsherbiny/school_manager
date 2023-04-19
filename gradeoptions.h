#ifndef GRADEOPTIONS_H
#define GRADEOPTIONS_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class GradeOptions : public QGraphicsView
{
public:
    GradeOptions();
    void show_window();
private:

//    QPushButton *femalePlanBtn, *femaleCircularsBtn, *femaleReportsBtn, *femaleAdditionalBtn, *backBtn;
//    QGraphicsProxyWidget *femalePlanBtnProxy, *femaleCircularsBtnProxy, *femaleReportsBtnProxy, *femaleAdditionalBtnProxy, *backBtnProxy;

    QPushButton *planBtn, *circularsBtn, *reportsBtn, *additionalBtn;
    QGraphicsProxyWidget *planBtnProxy, *circularsBtnProxy, *reportsBtnProxy, *additionalBtnProxy;

    void showGradeSelection ();
    void showDocumentViewer ();
};

#endif // GRADEOPTIONS_H

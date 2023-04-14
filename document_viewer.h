#ifndef DOCUMENT_VIEWER_H
#define DOCUMENT_VIEWER_H

#include <QPushButton>
#include <QGraphicsProxyWidget>

class Document_Viewer
{
public:
    Document_Viewer();
    void show_window();

private:
    QPushButton *next_document_btn, *previous_document_btn;
    QPushButton *document_preview_btn;
    QPushButton *load_file, *remove_file, *print_file;

    QGraphicsProxyWidget *next_document_proxy, *previous_document_proxy;
    QGraphicsProxyWidget *document_preview_proxy;
    QGraphicsProxyWidget *load_file_proxy, *remove_file_proxy, *print_file_proxy;
};

#endif // DOCUMENT_VIEWER_H

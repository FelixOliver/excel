#ifndef PREVIEWPRINT_H
#define PREVIEWPRINT_H

#include <QTableView>

QT_BEGIN_NAMESPACE
class QPrinter;
QT_END_NAMESPACE


class PreviewPrint:public QTableView
{
    Q_OBJECT
    public:
        PreviewPrint();
    public Q_SLOTS:
        void print(QPrinter *printer);
};

#endif // PREVIEWPRINT_H

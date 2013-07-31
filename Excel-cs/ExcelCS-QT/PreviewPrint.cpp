#ifndef QT_NO_PRINTER

#include <QPrinter>

#endif
#include <QStyleOptionViewItem>
#include "PreviewPrint.h"

PreviewPrint::PreviewPrint()
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void PreviewPrint::print(QPrinter *printer)
{
    #ifndef QT_NO_PRINTER
    resize(printer->width(), printer->height());
    render(printer);
    #endif
}


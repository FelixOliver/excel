/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ExcelCS-QT/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 33),
QT_MOC_LITERAL(4, 58, 10),
QT_MOC_LITERAL(5, 69, 13),
QT_MOC_LITERAL(6, 83, 11),
QT_MOC_LITERAL(7, 95, 14),
QT_MOC_LITERAL(8, 110, 26),
QT_MOC_LITERAL(9, 137, 17),
QT_MOC_LITERAL(10, 155, 4),
QT_MOC_LITERAL(11, 160, 23),
QT_MOC_LITERAL(12, 184, 24),
QT_MOC_LITERAL(13, 209, 21),
QT_MOC_LITERAL(14, 231, 22),
QT_MOC_LITERAL(15, 254, 23),
QT_MOC_LITERAL(16, 278, 43),
QT_MOC_LITERAL(17, 322, 22),
QT_MOC_LITERAL(18, 345, 23),
QT_MOC_LITERAL(19, 369, 22)
    },
    "MainWindow\0load_matrix\0\0"
    "on_SpreadSheet_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_SpreadSheet_itemChanged\0"
    "QTableWidgetItem*\0item\0on_Button_Print_clicked\0"
    "on_actionPrint_triggered\0on_Button_New_clicked\0"
    "on_actionNew_triggered\0on_actionQuit_triggered\0"
    "on_actionAbout_Excel_CS_v_3_14_16_triggered\0"
    "on_Button_Save_clicked\0on_actionSave_triggered\0"
    "on_Button_Open_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    4,   75,    2, 0x08,
       8,    1,   84,    2, 0x08,
      11,    0,   87,    2, 0x08,
      12,    0,   88,    2, 0x08,
      13,    0,   89,    2, 0x08,
      14,    0,   90,    2, 0x08,
      15,    0,   91,    2, 0x08,
      16,    0,   92,    2, 0x08,
      17,    0,   93,    2, 0x08,
      18,    0,   94,    2, 0x08,
      19,    0,   95,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->load_matrix(); break;
        case 1: _t->on_SpreadSheet_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->on_SpreadSheet_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_Button_Print_clicked(); break;
        case 4: _t->on_actionPrint_triggered(); break;
        case 5: _t->on_Button_New_clicked(); break;
        case 6: _t->on_actionNew_triggered(); break;
        case 7: _t->on_actionQuit_triggered(); break;
        case 8: _t->on_actionAbout_Excel_CS_v_3_14_16_triggered(); break;
        case 9: _t->on_Button_Save_clicked(); break;
        case 10: _t->on_actionSave_triggered(); break;
        case 11: _t->on_Button_Open_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

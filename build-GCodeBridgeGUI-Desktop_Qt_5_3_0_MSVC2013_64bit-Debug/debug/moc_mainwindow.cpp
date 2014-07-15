/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GCodeBridgeGUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 8),
QT_MOC_LITERAL(4, 30, 21),
QT_MOC_LITERAL(5, 52, 24),
QT_MOC_LITERAL(6, 77, 8),
QT_MOC_LITERAL(7, 86, 20),
QT_MOC_LITERAL(8, 107, 28),
QT_MOC_LITERAL(9, 136, 29),
QT_MOC_LITERAL(10, 166, 23),
QT_MOC_LITERAL(11, 190, 30),
QT_MOC_LITERAL(12, 221, 4),
QT_MOC_LITERAL(13, 226, 30),
QT_MOC_LITERAL(14, 257, 30),
QT_MOC_LITERAL(15, 288, 28),
QT_MOC_LITERAL(16, 317, 28),
QT_MOC_LITERAL(17, 346, 28),
QT_MOC_LITERAL(18, 375, 15),
QT_MOC_LITERAL(19, 391, 40),
QT_MOC_LITERAL(20, 432, 5)
    },
    "MainWindow\0openFile\0\0fileName\0"
    "on_saveButton_clicked\0on_discardButton_clicked\0"
    "saveFile\0on_mixButton_clicked\0"
    "on_origGCodeLocation_clicked\0"
    "on_mixedGCodeLocation_clicked\0"
    "on_saveAsButton_clicked\0"
    "on_startingRatio1_valueChanged\0arg1\0"
    "on_startingRatio2_valueChanged\0"
    "on_startingRatio3_valueChanged\0"
    "on_endingRatio1_valueChanged\0"
    "on_endingRatio2_valueChanged\0"
    "on_endingRatio3_valueChanged\0"
    "calibrateRatios\0"
    "on_origGCodeComboBox_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       1,    1,  100,    2, 0x08 /* Private */,
       4,    0,  103,    2, 0x08 /* Private */,
       5,    0,  104,    2, 0x08 /* Private */,
       6,    1,  105,    2, 0x08 /* Private */,
       7,    0,  108,    2, 0x08 /* Private */,
       8,    0,  109,    2, 0x08 /* Private */,
       9,    0,  110,    2, 0x08 /* Private */,
      10,    0,  111,    2, 0x08 /* Private */,
      11,    1,  112,    2, 0x08 /* Private */,
      13,    1,  115,    2, 0x08 /* Private */,
      14,    1,  118,    2, 0x08 /* Private */,
      15,    1,  121,    2, 0x08 /* Private */,
      16,    1,  124,    2, 0x08 /* Private */,
      17,    1,  127,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    1,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_saveButton_clicked(); break;
        case 3: _t->on_discardButton_clicked(); break;
        case 4: _t->saveFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_mixButton_clicked(); break;
        case 6: _t->on_origGCodeLocation_clicked(); break;
        case 7: _t->on_mixedGCodeLocation_clicked(); break;
        case 8: _t->on_saveAsButton_clicked(); break;
        case 9: _t->on_startingRatio1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_startingRatio2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_startingRatio3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_endingRatio1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_endingRatio2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_endingRatio3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->calibrateRatios(); break;
        case 16: _t->on_origGCodeComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

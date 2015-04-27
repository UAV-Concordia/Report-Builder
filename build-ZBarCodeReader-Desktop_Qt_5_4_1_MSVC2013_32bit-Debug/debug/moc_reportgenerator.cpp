/****************************************************************************
** Meta object code from reading C++ file 'reportgenerator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZBarCodeReader/reportgenerator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reportgenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReportGenerator_t {
    QByteArrayData data[11];
    char stringdata[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReportGenerator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReportGenerator_t qt_meta_stringdata_ReportGenerator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ReportGenerator"
QT_MOC_LITERAL(1, 16, 25), // "on_generateReport_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 31), // "on_loadObjectFileButton_clicked"
QT_MOC_LITERAL(4, 75, 32), // "on_loadSurfaceFileButton_clicked"
QT_MOC_LITERAL(5, 108, 25), // "on_loadVolumeFile_clicked"
QT_MOC_LITERAL(6, 134, 31), // "on_loadPointImageFile_2_clicked"
QT_MOC_LITERAL(7, 166, 28), // "on_refreshListButton_clicked"
QT_MOC_LITERAL(8, 195, 22), // "on_featureList_clicked"
QT_MOC_LITERAL(9, 218, 5), // "index"
QT_MOC_LITERAL(10, 224, 32) // "on_copyToClipboardButton_clicked"

    },
    "ReportGenerator\0on_generateReport_clicked\0"
    "\0on_loadObjectFileButton_clicked\0"
    "on_loadSurfaceFileButton_clicked\0"
    "on_loadVolumeFile_clicked\0"
    "on_loadPointImageFile_2_clicked\0"
    "on_refreshListButton_clicked\0"
    "on_featureList_clicked\0index\0"
    "on_copyToClipboardButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReportGenerator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,

       0        // eod
};

void ReportGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReportGenerator *_t = static_cast<ReportGenerator *>(_o);
        switch (_id) {
        case 0: _t->on_generateReport_clicked(); break;
        case 1: _t->on_loadObjectFileButton_clicked(); break;
        case 2: _t->on_loadSurfaceFileButton_clicked(); break;
        case 3: _t->on_loadVolumeFile_clicked(); break;
        case 4: _t->on_loadPointImageFile_2_clicked(); break;
        case 5: _t->on_refreshListButton_clicked(); break;
        case 6: _t->on_featureList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_copyToClipboardButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ReportGenerator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ReportGenerator.data,
      qt_meta_data_ReportGenerator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReportGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReportGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReportGenerator.stringdata))
        return static_cast<void*>(const_cast< ReportGenerator*>(this));
    return QWidget::qt_metacast(_clname);
}

int ReportGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

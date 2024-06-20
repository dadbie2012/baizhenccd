/****************************************************************************
** Meta object code from reading C++ file 'axisthreadone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../motioncontrol/axisthreadone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisthreadone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_axisThreadOne_t {
    QByteArrayData data[11];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_axisThreadOne_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_axisThreadOne_t qt_meta_stringdata_axisThreadOne = {
    {
QT_MOC_LITERAL(0, 0, 13), // "axisThreadOne"
QT_MOC_LITERAL(1, 14, 17), // "slotAxisMoveRelPT"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 12), // "acceleration"
QT_MOC_LITERAL(5, 52, 8), // "distance"
QT_MOC_LITERAL(6, 61, 4), // "time"
QT_MOC_LITERAL(7, 66, 17), // "slotAxisMoveAbsPT"
QT_MOC_LITERAL(8, 84, 22), // "slotAxisGroupMoveAbsPT"
QT_MOC_LITERAL(9, 107, 14), // "QVector<ulong>"
QT_MOC_LITERAL(10, 122, 15) // "QVector<double>"

    },
    "axisThreadOne\0slotAxisMoveRelPT\0\0index\0"
    "acceleration\0distance\0time\0slotAxisMoveAbsPT\0"
    "slotAxisGroupMoveAbsPT\0QVector<ulong>\0"
    "QVector<double>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_axisThreadOne[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x0a /* Public */,
       7,    4,   38,    2, 0x0a /* Public */,
       8,    4,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10,    3,    4,    5,    6,

       0        // eod
};

void axisThreadOne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<axisThreadOne *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotAxisMoveRelPT((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->slotAxisMoveAbsPT((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: _t->slotAxisGroupMoveAbsPT((*reinterpret_cast< QVector<ulong>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<ulong> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject axisThreadOne::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_axisThreadOne.data,
    qt_meta_data_axisThreadOne,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *axisThreadOne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *axisThreadOne::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_axisThreadOne.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int axisThreadOne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

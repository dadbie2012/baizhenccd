/****************************************************************************
** Meta object code from reading C++ file 'axisthreadthree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../motioncontrol/axisthreadthree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisthreadthree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_axisThreadThree_t {
    QByteArrayData data[16];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_axisThreadThree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_axisThreadThree_t qt_meta_stringdata_axisThreadThree = {
    {
QT_MOC_LITERAL(0, 0, 15), // "axisThreadThree"
QT_MOC_LITERAL(1, 16, 18), // "AxisGetAllRealData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "slotDeviceOpen"
QT_MOC_LITERAL(4, 51, 15), // "slotDeviceClose"
QT_MOC_LITERAL(5, 67, 14), // "slotAxisEnable"
QT_MOC_LITERAL(6, 82, 12), // "QVector<int>"
QT_MOC_LITERAL(7, 95, 5), // "index"
QT_MOC_LITERAL(8, 101, 15), // "slotAxisDisable"
QT_MOC_LITERAL(9, 117, 15), // "slotAxisPowerOn"
QT_MOC_LITERAL(10, 133, 16), // "slotAxisPowerOff"
QT_MOC_LITERAL(11, 150, 21), // "slotAxisErrorAllClear"
QT_MOC_LITERAL(12, 172, 15), // "slotAxisAllStop"
QT_MOC_LITERAL(13, 188, 12), // "slotAxisStop"
QT_MOC_LITERAL(14, 201, 13), // "slotAxisReset"
QT_MOC_LITERAL(15, 215, 14) // "slotAxisGohome"

    },
    "axisThreadThree\0AxisGetAllRealData\0\0"
    "slotDeviceOpen\0slotDeviceClose\0"
    "slotAxisEnable\0QVector<int>\0index\0"
    "slotAxisDisable\0slotAxisPowerOn\0"
    "slotAxisPowerOff\0slotAxisErrorAllClear\0"
    "slotAxisAllStop\0slotAxisStop\0slotAxisReset\0"
    "slotAxisGohome"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_axisThreadThree[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    1,   87,    2, 0x0a /* Public */,
      14,    1,   90,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULong,    7,
    QMetaType::Void, QMetaType::ULong,    7,
    QMetaType::Void, QMetaType::ULong,    7,

       0        // eod
};

void axisThreadThree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<axisThreadThree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AxisGetAllRealData(); break;
        case 1: _t->slotDeviceOpen(); break;
        case 2: _t->slotDeviceClose(); break;
        case 3: _t->slotAxisEnable((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 4: _t->slotAxisDisable((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 5: _t->slotAxisPowerOn(); break;
        case 6: _t->slotAxisPowerOff(); break;
        case 7: _t->slotAxisErrorAllClear(); break;
        case 8: _t->slotAxisAllStop(); break;
        case 9: _t->slotAxisStop((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 10: _t->slotAxisReset((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 11: _t->slotAxisGohome((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject axisThreadThree::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_axisThreadThree.data,
    qt_meta_data_axisThreadThree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *axisThreadThree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *axisThreadThree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_axisThreadThree.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int axisThreadThree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'axisthreadtwo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../motioncontrol/axisthreadtwo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisthreadtwo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_axisThreadTwo_t {
    QByteArrayData data[17];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_axisThreadTwo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_axisThreadTwo_t qt_meta_stringdata_axisThreadTwo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "axisThreadTwo"
QT_MOC_LITERAL(1, 14, 10), // "sigendmove"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "sigendmove2"
QT_MOC_LITERAL(4, 38, 11), // "sigendmove3"
QT_MOC_LITERAL(5, 50, 11), // "sigendmove4"
QT_MOC_LITERAL(6, 62, 14), // "sigendmove_2_1"
QT_MOC_LITERAL(7, 77, 14), // "sigendmove_2_2"
QT_MOC_LITERAL(8, 92, 14), // "sigendmove_2_3"
QT_MOC_LITERAL(9, 107, 14), // "sigendmove_2_4"
QT_MOC_LITERAL(10, 122, 20), // "slot_getDistanceTime"
QT_MOC_LITERAL(11, 143, 6), // "axhand"
QT_MOC_LITERAL(12, 150, 5), // "axis*"
QT_MOC_LITERAL(13, 156, 4), // "axis"
QT_MOC_LITERAL(14, 161, 21), // "slot_getDistanceTime2"
QT_MOC_LITERAL(15, 183, 21), // "slot_getDistanceTime3"
QT_MOC_LITERAL(16, 205, 21) // "slot_getDistanceTime4"

    },
    "axisThreadTwo\0sigendmove\0\0sigendmove2\0"
    "sigendmove3\0sigendmove4\0sigendmove_2_1\0"
    "sigendmove_2_2\0sigendmove_2_3\0"
    "sigendmove_2_4\0slot_getDistanceTime\0"
    "axhand\0axis*\0axis\0slot_getDistanceTime2\0"
    "slot_getDistanceTime3\0slot_getDistanceTime4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_axisThreadTwo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   82,    2, 0x0a /* Public */,
      14,    2,   87,    2, 0x0a /* Public */,
      15,    2,   92,    2, 0x0a /* Public */,
      16,    2,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,

       0        // eod
};

void axisThreadTwo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<axisThreadTwo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigendmove(); break;
        case 1: _t->sigendmove2(); break;
        case 2: _t->sigendmove3(); break;
        case 3: _t->sigendmove4(); break;
        case 4: _t->sigendmove_2_1(); break;
        case 5: _t->sigendmove_2_2(); break;
        case 6: _t->sigendmove_2_3(); break;
        case 7: _t->sigendmove_2_4(); break;
        case 8: _t->slot_getDistanceTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< axis*(*)>(_a[2]))); break;
        case 9: _t->slot_getDistanceTime2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< axis*(*)>(_a[2]))); break;
        case 10: _t->slot_getDistanceTime3((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< axis*(*)>(_a[2]))); break;
        case 11: _t->slot_getDistanceTime4((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< axis*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< axis* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< axis* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< axis* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< axis* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove4)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove_2_1)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove_2_2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove_2_3)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (axisThreadTwo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&axisThreadTwo::sigendmove_2_4)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject axisThreadTwo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_axisThreadTwo.data,
    qt_meta_data_axisThreadTwo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *axisThreadTwo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *axisThreadTwo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_axisThreadTwo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int axisThreadTwo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void axisThreadTwo::sigendmove()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void axisThreadTwo::sigendmove2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void axisThreadTwo::sigendmove3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void axisThreadTwo::sigendmove4()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void axisThreadTwo::sigendmove_2_1()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void axisThreadTwo::sigendmove_2_2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void axisThreadTwo::sigendmove_2_3()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void axisThreadTwo::sigendmove_2_4()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

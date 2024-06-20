/****************************************************************************
** Meta object code from reading C++ file 'chuankou.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chuankou.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chuankou.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChuanKou_t {
    QByteArrayData data[15];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChuanKou_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChuanKou_t qt_meta_stringdata_ChuanKou = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChuanKou"
QT_MOC_LITERAL(1, 9, 7), // "sendLog"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "log"
QT_MOC_LITERAL(4, 22, 15), // "sendlightchange"
QT_MOC_LITERAL(5, 38, 9), // "situation"
QT_MOC_LITERAL(6, 48, 3), // "num"
QT_MOC_LITERAL(7, 52, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 74, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(9, 98, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 122, 14), // "getinformation"
QT_MOC_LITERAL(11, 137, 20), // "on_openlight_clicked"
QT_MOC_LITERAL(12, 158, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(13, 182, 9), // "openlight"
QT_MOC_LITERAL(14, 192, 10) // "closelight"

    },
    "ChuanKou\0sendLog\0\0log\0sendlightchange\0"
    "situation\0num\0on_pushButton_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_2_clicked\0"
    "getinformation\0on_openlight_clicked\0"
    "on_pushButton_4_clicked\0openlight\0"
    "closelight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChuanKou[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    2,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void ChuanKou::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChuanKou *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendlightchange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->getinformation(); break;
        case 6: _t->on_openlight_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->openlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->closelight((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChuanKou::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChuanKou::sendLog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChuanKou::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChuanKou::sendlightchange)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChuanKou::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChuanKou.data,
    qt_meta_data_ChuanKou,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChuanKou::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChuanKou::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChuanKou.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChuanKou::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ChuanKou::sendLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChuanKou::sendlightchange(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

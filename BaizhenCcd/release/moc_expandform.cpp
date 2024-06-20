/****************************************************************************
** Meta object code from reading C++ file 'expandform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../expandform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QQueue>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expandform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExpandForm_t {
    QByteArrayData data[29];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExpandForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExpandForm_t qt_meta_stringdata_ExpandForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ExpandForm"
QT_MOC_LITERAL(1, 11, 8), // "SigColor"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 16), // "autofocusroirect"
QT_MOC_LITERAL(4, 38, 4), // "Rect"
QT_MOC_LITERAL(5, 43, 3), // "roi"
QT_MOC_LITERAL(6, 47, 14), // "autofocusstart"
QT_MOC_LITERAL(7, 62, 8), // "getimage"
QT_MOC_LITERAL(8, 71, 15), // "QQueue<QPixmap>"
QT_MOC_LITERAL(9, 87, 10), // "ImageQueue"
QT_MOC_LITERAL(10, 98, 19), // "VisionDaHengCamera*"
QT_MOC_LITERAL(11, 118, 6), // "camera"
QT_MOC_LITERAL(12, 125, 21), // "acceptautofocussignal"
QT_MOC_LITERAL(13, 147, 9), // "getresult"
QT_MOC_LITERAL(14, 157, 3), // "Mat"
QT_MOC_LITERAL(15, 161, 5), // "image"
QT_MOC_LITERAL(16, 167, 14), // "vector<double>"
QT_MOC_LITERAL(17, 182, 6), // "result"
QT_MOC_LITERAL(18, 189, 19), // "getresult_autofocus"
QT_MOC_LITERAL(19, 209, 13), // "OnZoomInImage"
QT_MOC_LITERAL(20, 223, 14), // "OnZoomOutImage"
QT_MOC_LITERAL(21, 238, 13), // "OnPresetImage"
QT_MOC_LITERAL(22, 252, 9), // "getzhenlv"
QT_MOC_LITERAL(23, 262, 6), // "zhenlv"
QT_MOC_LITERAL(24, 269, 15), // "gettriggerimage"
QT_MOC_LITERAL(25, 285, 6), // "pixmap"
QT_MOC_LITERAL(26, 292, 9), // "getqimage"
QT_MOC_LITERAL(27, 302, 7), // "QMutex*"
QT_MOC_LITERAL(28, 310, 5) // "mutex"

    },
    "ExpandForm\0SigColor\0\0autofocusroirect\0"
    "Rect\0roi\0autofocusstart\0getimage\0"
    "QQueue<QPixmap>\0ImageQueue\0"
    "VisionDaHengCamera*\0camera\0"
    "acceptautofocussignal\0getresult\0Mat\0"
    "image\0vector<double>\0result\0"
    "getresult_autofocus\0OnZoomInImage\0"
    "OnZoomOutImage\0OnPresetImage\0getzhenlv\0"
    "zhenlv\0gettriggerimage\0pixmap\0getqimage\0"
    "QMutex*\0mutex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpandForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       3,    1,   86,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   90,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    2,   96,    2, 0x0a /* Public */,
      18,    1,  101,    2, 0x0a /* Public */,
      19,    0,  104,    2, 0x0a /* Public */,
      20,    0,  105,    2, 0x0a /* Public */,
      21,    0,  106,    2, 0x0a /* Public */,
      22,    1,  107,    2, 0x0a /* Public */,
      24,    1,  110,    2, 0x0a /* Public */,
      26,    2,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   15,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::QPixmap,   25,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 27,   15,   28,

       0        // eod
};

void ExpandForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExpandForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->autofocusroirect((*reinterpret_cast< Rect(*)>(_a[1]))); break;
        case 2: _t->autofocusstart(); break;
        case 3: _t->getimage((*reinterpret_cast< QQueue<QPixmap>(*)>(_a[1])),(*reinterpret_cast< VisionDaHengCamera*(*)>(_a[2]))); break;
        case 4: _t->acceptautofocussignal(); break;
        case 5: _t->getresult((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2]))); break;
        case 6: _t->getresult_autofocus((*reinterpret_cast< vector<double>(*)>(_a[1]))); break;
        case 7: _t->OnZoomInImage(); break;
        case 8: _t->OnZoomOutImage(); break;
        case 9: _t->OnPresetImage(); break;
        case 10: _t->getzhenlv((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->gettriggerimage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 12: _t->getqimage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QMutex*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQueue<QPixmap> >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VisionDaHengCamera* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExpandForm::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExpandForm::SigColor)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExpandForm::*)(Rect );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExpandForm::autofocusroirect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ExpandForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExpandForm::autofocusstart)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ExpandForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ExpandForm.data,
    qt_meta_data_ExpandForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ExpandForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpandForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExpandForm.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ExpandForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ExpandForm::SigColor(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExpandForm::autofocusroirect(Rect _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExpandForm::autofocusstart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

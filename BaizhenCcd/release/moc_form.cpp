/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QQueue>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_t {
    QByteArrayData data[24];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_t qt_meta_stringdata_Form = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Form"
QT_MOC_LITERAL(1, 5, 8), // "SigColor"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "getimage"
QT_MOC_LITERAL(4, 24, 15), // "QQueue<QPixmap>"
QT_MOC_LITERAL(5, 40, 10), // "ImageQueue"
QT_MOC_LITERAL(6, 51, 19), // "VisionDaHengCamera*"
QT_MOC_LITERAL(7, 71, 6), // "camera"
QT_MOC_LITERAL(8, 78, 9), // "getimage2"
QT_MOC_LITERAL(9, 88, 3), // "Mat"
QT_MOC_LITERAL(10, 92, 5), // "image"
QT_MOC_LITERAL(11, 98, 9), // "getresult"
QT_MOC_LITERAL(12, 108, 14), // "vector<double>"
QT_MOC_LITERAL(13, 123, 6), // "result"
QT_MOC_LITERAL(14, 130, 13), // "OnZoomInImage"
QT_MOC_LITERAL(15, 144, 14), // "OnZoomOutImage"
QT_MOC_LITERAL(16, 159, 13), // "OnPresetImage"
QT_MOC_LITERAL(17, 173, 9), // "getzhenlv"
QT_MOC_LITERAL(18, 183, 6), // "zhenlv"
QT_MOC_LITERAL(19, 190, 15), // "gettriggerimage"
QT_MOC_LITERAL(20, 206, 6), // "pixmap"
QT_MOC_LITERAL(21, 213, 9), // "getqimage"
QT_MOC_LITERAL(22, 223, 7), // "QMutex*"
QT_MOC_LITERAL(23, 231, 5) // "mutex"

    },
    "Form\0SigColor\0\0getimage\0QQueue<QPixmap>\0"
    "ImageQueue\0VisionDaHengCamera*\0camera\0"
    "getimage2\0Mat\0image\0getresult\0"
    "vector<double>\0result\0OnZoomInImage\0"
    "OnZoomOutImage\0OnPresetImage\0getzhenlv\0"
    "zhenlv\0gettriggerimage\0pixmap\0getqimage\0"
    "QMutex*\0mutex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   71,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      11,    2,   79,    2, 0x0a /* Public */,
      14,    0,   84,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,
      16,    0,   86,    2, 0x0a /* Public */,
      17,    1,   87,    2, 0x0a /* Public */,
      19,    1,   90,    2, 0x0a /* Public */,
      21,    2,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 12,   10,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void, QMetaType::QPixmap,   20,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 22,   10,   23,

       0        // eod
};

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->getimage((*reinterpret_cast< QQueue<QPixmap>(*)>(_a[1])),(*reinterpret_cast< VisionDaHengCamera*(*)>(_a[2]))); break;
        case 2: _t->getimage2((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 3: _t->getresult((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2]))); break;
        case 4: _t->OnZoomInImage(); break;
        case 5: _t->OnZoomOutImage(); break;
        case 6: _t->OnPresetImage(); break;
        case 7: _t->getzhenlv((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->gettriggerimage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 9: _t->getqimage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QMutex*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            using _t = void (Form::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form::SigColor)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Form::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_Form.data,
    qt_meta_data_Form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Form::SigColor(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

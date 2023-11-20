/****************************************************************************
** Meta object code from reading C++ file 'Check.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sender01/Check.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Check.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Check_t {
    QByteArrayData data[13];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Check_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Check_t qt_meta_stringdata_Check = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Check"
QT_MOC_LITERAL(1, 6, 12), // "dataComplete"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "stopOver"
QT_MOC_LITERAL(4, 29, 5), // "Route"
QT_MOC_LITERAL(5, 35, 9), // "LocalPort"
QT_MOC_LITERAL(6, 45, 13), // "receiveInform"
QT_MOC_LITERAL(7, 59, 2), // "Id"
QT_MOC_LITERAL(8, 62, 10), // "receiveCmd"
QT_MOC_LITERAL(9, 73, 8), // "makeData"
QT_MOC_LITERAL(10, 82, 11), // "checkStatus"
QT_MOC_LITERAL(11, 94, 7), // "setData"
QT_MOC_LITERAL(12, 102, 10) // "exitThread"

    },
    "Check\0dataComplete\0\0stopOver\0Route\0"
    "LocalPort\0receiveInform\0Id\0receiveCmd\0"
    "makeData\0checkStatus\0setData\0exitThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Check[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   60,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::UShort,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::Int, QMetaType::Int,    5,    4,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Check::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Check *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataComplete(); break;
        case 1: _t->stopOver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->receiveInform((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->receiveCmd(); break;
        case 4: _t->makeData(); break;
        case 5: _t->checkStatus(); break;
        case 6: _t->setData(); break;
        case 7: _t->exitThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Check::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Check::dataComplete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Check::*)(int , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Check::stopOver)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Check::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Check.data,
    qt_meta_data_Check,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Check::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Check::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Check.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Check::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Check::dataComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Check::stopOver(int _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

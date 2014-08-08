/****************************************************************************
** Meta object code from reading C++ file 'searchwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qDB/searchwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SearchWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,
      45,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   13,   13,   13, 0x08,
      99,   13,   13,   13, 0x08,
     127,   13,   13,   13, 0x08,
     155,   13,   13,   13, 0x08,
     186,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SearchWindow[] = {
    "SearchWindow\0\0,\0nameChanged(QString,QString)\0"
    "torneoRemove(QString)\0"
    "on_searchDeleteButton_clicked()\0"
    "on_editNomeButton_clicked()\0"
    "on_editGiocButton_clicked()\0"
    "on_editImportoButton_clicked()\0"
    "on_editBuyInButton_clicked()\0"
};

void SearchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SearchWindow *_t = static_cast<SearchWindow *>(_o);
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->torneoRemove((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_searchDeleteButton_clicked(); break;
        case 3: _t->on_editNomeButton_clicked(); break;
        case 4: _t->on_editGiocButton_clicked(); break;
        case 5: _t->on_editImportoButton_clicked(); break;
        case 6: _t->on_editBuyInButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SearchWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SearchWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SearchWindow,
      qt_meta_data_SearchWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SearchWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SearchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SearchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchWindow))
        return static_cast<void*>(const_cast< SearchWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int SearchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SearchWindow::nameChanged(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchWindow::torneoRemove(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

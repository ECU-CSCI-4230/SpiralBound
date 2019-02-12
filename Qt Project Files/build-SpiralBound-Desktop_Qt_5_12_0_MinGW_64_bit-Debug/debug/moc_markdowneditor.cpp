/****************************************************************************
** Meta object code from reading C++ file 'markdowneditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SpiralBound/markdowneditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'markdowneditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MarkdownEditor_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkdownEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkdownEditor_t qt_meta_stringdata_MarkdownEditor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MarkdownEditor"
QT_MOC_LITERAL(1, 15, 4), // "bold"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "italic"
QT_MOC_LITERAL(4, 28, 12), // "strikethough"
QT_MOC_LITERAL(5, 41, 11), // "makeComment"
QT_MOC_LITERAL(6, 53, 10), // "indentText"
QT_MOC_LITERAL(7, 64, 12), // "unindentText"
QT_MOC_LITERAL(8, 77, 12), // "insertBullet"
QT_MOC_LITERAL(9, 90, 13), // "insertNumeral"
QT_MOC_LITERAL(10, 104, 10) // "insertTask"

    },
    "MarkdownEditor\0bold\0\0italic\0strikethough\0"
    "makeComment\0indentText\0unindentText\0"
    "insertBullet\0insertNumeral\0insertTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkdownEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MarkdownEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MarkdownEditor *_t = static_cast<MarkdownEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bold(); break;
        case 1: _t->italic(); break;
        case 2: _t->strikethough(); break;
        case 3: _t->makeComment(); break;
        case 4: _t->indentText(); break;
        case 5: _t->unindentText(); break;
        case 6: _t->insertBullet(); break;
        case 7: _t->insertNumeral(); break;
        case 8: _t->insertTask(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MarkdownEditor::staticMetaObject = { {
    &QPlainTextEdit::staticMetaObject,
    qt_meta_stringdata_MarkdownEditor.data,
    qt_meta_data_MarkdownEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkdownEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkdownEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkdownEditor.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int MarkdownEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

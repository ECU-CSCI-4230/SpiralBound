#ifndef MARKDOWNEDITOR_H
#define MARKDOWNEDITOR_H

#include <QObject>
#include <QPlainTextEdit>
#include <QString>
#include <QEvent>
#include <QTextCursor>
#include <QRegularExpression>

/**
 * @brief The MarkdownEditor class
 * Markdown editor with basic shortcut keys
 */
// this statement means that Markdown Editor inherits QPlainTextEdit
class MarkdownEditor : QPlainTextEdit
{
    Q_OBJECT

public:
    MarkdownEditor();

public slots:
    void bold();
    void italic();
    void strikethough();
};


#endif // MARKDOWNEDITOR_H

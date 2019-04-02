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
    MarkdownEditor(QPlainTextEdit* edit);

public slots:
    void bold();
    void italic();
    void underline();
    void strikethough();
    void makeComment();
    void indentText();
    void unindentText();
    void insertBullet();
    void insertNumeral();
    void insertTask();
    bool detectBullet();
    bool detectEnum();

private:
    void addMarkupFormatting(const QString& markup);
    QPlainTextEdit* editor;
};

#endif // MARKDOWNEDITOR_H

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

signals:
  void keyCaught(QKeyEvent *e);

protected:
  virtual void keyPressEvent(QKeyEvent *event);

public slots:
    QTextCursor bold();
    QTextCursor italic();
    QTextCursor underline();
    QTextCursor strikethough();
    void makeComment();
    void indentText();
    void unindentText();
    void insertBullet();
    void insertNumeral();
    bool detectBullet();
    bool detectEnum();

private:
    QTextCursor addMarkupFormatting(const QString& markup);
    QPlainTextEdit* editor;
};

#endif // MARKDOWNEDITOR_H

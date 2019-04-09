#include "markdowneditor.h"
#include "qdebug.h"

MarkdownEditor::MarkdownEditor(QPlainTextEdit* edit)
{
    editor = edit;
}

QTextCursor MarkdownEditor::addMarkupFormatting(const QString &markup)
{
    QTextCursor cursor = editor->textCursor();
    // so we want to add the formatting string to the beginning and the end of the text.
    // if there is already text highlighted, we want to add the formatting to the beginning
    // and end of the formatting.
    // Otherwise we want to just add two instances of the formatting to the current
    // cursor position.

    // we use edit blocks to treat these individual actions as a single action for undo/redo
    // purposes.
    if (cursor.hasSelection())
    {
        int beginning = cursor.selectionStart();
        int end = cursor.selectionEnd();

        cursor.beginEditBlock();
        cursor.setPosition(end);
        cursor.insertText(markup);
        end = cursor.position();
        cursor.setPosition(beginning);
        cursor.insertText(markup);
        cursor.clearSelection();
        cursor.setPosition(end);
        cursor.endEditBlock();
        return cursor;
    }
    else
    {
        cursor.beginEditBlock();
        cursor.insertText(markup);
        int the_right_place = cursor.position();
        cursor.insertText(markup);
        cursor.setPosition(the_right_place);
        cursor.endEditBlock();
        return cursor;
    }
}

QTextCursor MarkdownEditor::bold() { return addMarkupFormatting("**");}
QTextCursor MarkdownEditor::italic() { return addMarkupFormatting("*"); }
QTextCursor MarkdownEditor::strikethough() { return addMarkupFormatting("~~"); }
QTextCursor MarkdownEditor::underline() { return addMarkupFormatting("_"); }

void MarkdownEditor::makeComment() {}

void MarkdownEditor::indentText() {}

void MarkdownEditor::unindentText() {}

void MarkdownEditor::insertBullet()
{
    QTextCursor cursor = editor->textCursor();
    int currentPosition = cursor.position();
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
    cursor.insertText("* ");
    cursor.setPosition(currentPosition);
    cursor.endEditBlock();
}

void MarkdownEditor::insertNumeral()
{
    QTextCursor cursor = editor->textCursor();
    int currentPosition = cursor.position();
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
    cursor.insertText("1. ");
    cursor.setPosition(currentPosition);
    cursor.endEditBlock();
}

bool MarkdownEditor::detectEnum()
{
    // Remove duplicated code and implement better
    QTextCursor cursor = editor->textCursor();
    int currentPosition = cursor.position();
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor, 1);
    QString seltext = cursor.selectedText();
    cursor.setPosition(currentPosition);
    cursor.endEditBlock();

    //build a regular expression to match against the alleged numeral
    QRegularExpression re;
    re.setPattern("^(\\d+)\\. ");
    QRegularExpressionMatch match = re.match(seltext);

    if (match.hasMatch())
    {
        qDebug() << "there's an enumeration";
        return true;
    }
    qDebug() << "there is no enumeration";
    return false;
}

bool MarkdownEditor::detectBullet()
{
    // Remove duplicated code and implement better
    QTextCursor cursor = editor->textCursor();
    int currentPosition = cursor.position();
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 2);
    QString seltext = cursor.selectedText();
    cursor.setPosition(currentPosition);
    cursor.endEditBlock();
    if (seltext == "* ")
    {
        return true;
    }
    return false;
}

// code comes from:
// https://www.qtcentre.org/threads/26892-How-get-signal-returnPressed-in-QTextEdit
void MarkdownEditor::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "a key was pressed";
    QTextCursor cur = textCursor();
    switch (e->key())
    {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            qDebug() << "enter was pressed";
        break;
    }
}

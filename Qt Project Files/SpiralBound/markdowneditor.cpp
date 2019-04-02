#include "markdowneditor.h"
#include "qdebug.h"

MarkdownEditor::MarkdownEditor(QPlainTextEdit* edit)
{
    editor = edit;
}

//fuck me sideways
void MarkdownEditor::addMarkupFormatting(const QString &markup)
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
        cursor.setPosition(beginning);
        cursor.insertText(markup);
        cursor.endEditBlock();
    }
    else
    {
        int beginning = cursor.position();
        cursor.beginEditBlock();
        cursor.insertText(markup);
        cursor.insertText(markup);
        cursor.setPosition(beginning, QTextCursor::KeepAnchor);
        cursor.endEditBlock();
    }
}

void MarkdownEditor::bold() { addMarkupFormatting("**"); }
void MarkdownEditor::italic() { addMarkupFormatting("*"); }
void MarkdownEditor::strikethough() { addMarkupFormatting("~~"); }
void MarkdownEditor::underline() { addMarkupFormatting("_"); }

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
    detectBullet();
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

void MarkdownEditor::insertTask() {}

bool MarkdownEditor::detectEnum()
{
    return false;
}

bool MarkdownEditor::detectBullet()
{
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

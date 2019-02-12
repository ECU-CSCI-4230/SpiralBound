#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor()
{
}

//fuck me sideways
void MarkdownEditor::addMarkupFormatting(const QString &markup)
{
    QTextCursor cursor = this->textCursor();

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
        cursor.setPosition(beginning);
        cursor.insertText(markup);
        cursor.setPosition(end);
        cursor.insertText(markup);
        cursor.endEditBlock();
    }
    else
    {
        cursor.beginEditBlock();
        cursor.insertText(markup);
        cursor.insertText(markup);
        cursor.endEditBlock();
    }
}

void MarkdownEditor::bold()
{
    addMarkupFormatting("**");
}

void MarkdownEditor::italic()
{
    addMarkupFormatting("*");
}

void MarkdownEditor::strikethough()
{
    addMarkupFormatting("~~");
}

void MarkdownEditor::makeComment(){}

void MarkdownEditor::indentText(){}

void MarkdownEditor::unindentText(){}

void MarkdownEditor::insertBullet(){}

void MarkdownEditor::insertNumeral(){}

void MarkdownEditor::insertTask(){}

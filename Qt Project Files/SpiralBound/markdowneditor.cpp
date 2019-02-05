#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor()
{
}

//fuck me sideways
void MarkdownEditor::addMarkupFormatting(const QString &markup){}

void MarkdownEditor::bold()
{
    addMarkupFormatting("**");
}

void MarkdownEditor::italic()
{
    addMarkupFormatting("*");
}

// A reminder that underline is not standard in markdown
void MarkdownEditor::underline()
{
    addMarkupFormatting("__");
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

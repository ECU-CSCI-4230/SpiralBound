#### DFE-01 (details HFE-01, HFE-02, HFE-03)
The user should be able to take notes with basic rich-text editing features, including but not limited to: bolding, italicization, and underlining of text; colorization of fonts; differentiation of code styling (mono-spaced font) from regular notes; and the indentation of notes using bulleted lists of ordered or unordered format.

~~The operation of text-editing should be in a block-based format, where each block contains a type of content as well as the content itself. These blocks should be easily inserted, deletable, and modifiable. _(This functionality is similar to JupyterLab Notebooks.)_~~

**Update 03-15-19**: The operation of text-editing should use Qt's built-in TextEdit widget, where each page is its own QTextDocument.

The text-editing window should, given a language, understand the basic syntax of that language, such as Java, CSS, or HTML, and display these programming languages in a font that is mono-spaced for ease of reading. The background of these sections should also be lightly darker in color than a regular text segment.

Word-wrap toggleability and customization of line-spacing features are optional.

#### DFE-02 (details HFE-04)
The program should automate the saving of content such that, should a crash happen, minimal content is lost on the part of the user (similar to OneNote notebooks). The user shouldn't be notified or otherwise impacted by the automated saving of notebook content, and only the most recent auto-save should be kept after the user saves their book (in the case of file corruption).

#### DNE-01 (details HFE-02)
Blocks of text/code should be contained within pages, with those pages contained within sections, and those sections within a single notebook instance. The notebook class itself should not directly have access to the properties of sections, pages, or block content, and vice versa. _(For example, to access a block's content, you must use book.getSection(...).getPage(...).getBlock(...) to first reach the block in question.)_

#### DNE-02
Text-editing should be easily understood (or intuitive) to those who do not understand Markdown syntax, allowing any experienced and inexperienced user to take notes using the interface.

#### Uncovered Requirements
HFE-05
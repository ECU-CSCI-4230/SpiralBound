## Classes, Functions, Files
### Main Window
**Files**: mainwindow.cpp/h/.ui, main.cpp
**Structures**: Deck, Event _(contained in `Util.h`)_

This trio of files is where most of the overarching interface design is located. This window contains the notebook, calendar, and study utility interfaces, and is where most, if not all, prompts should send data using signal emission. 

#### Calendar
**Files**: addcalendarevent.cpp/.h/.ui, deletecalendarevent.cpp/.h/.ui, editcalendarevent.cpp/.h/.ui

These nine source files are the central source for prompt windows for the calendar event list. `addcalendarevent` allows the insertion of calendar events, `deletecalendarevent` allows the deletion of, and `editcalendarevent` allows the editing of event data. The signals these classes emit is handled by the main window.

#### Notebook
**Files**: book.h/.cpp, section.h/.cpp, page.h/.cpp, ~~block.h/.cpp~~, util.h, markdowneditor.h/.cpp, editsection.h/.cpp/.ui, document.h/.cpp
**Testing**: unit_book.h/.cpp

These source files are the main controller for the notebook data structure, allowing the construction, saving of (to string), and reading in (from string). The book class is instantiated in the main window, and will be handled primarily there. The class `markdowneditor` is instantiated, as well, in the main window, and is used to generate markdown formatting in that window.

The `util` class provides helper functions that are used in the book data structure classes. It also provides an Event and Deck data structure for usage in loading information from the disk.

There is another class, `editsection`, that opens when a section entry is double-clicked. It allows the user to customize the name and the color of that section as viewed in the section-page structure. The main window handles the signals sent by this prompt.

**Update 3/18/2019**: The Block data structure is being retconned in favor of storing QTextDocument pointers in the page class. As such, they no longer apply.

#### Study Tool
**Files**: addcard.cpp/.h/.ui, deletecard.cpp/.h/.ui, importflashcards.cpp/.h/.ui, adddeck.cpp/.h/.ui, deletedeck.cpp/.h/.ui

These source files are the central source for prompt windows for the study utility, allowing the user to add cards (`addcard`), remove cards using `deletecard`, and import a series of flash cards from a CSV file (`importflashcards`). The signals that these prompts emit is handled in the main window. There are also source files for adding and deleting decks.

### Study Window
**Files**: studycard.cpp/.h/.ui

These source files relate to the studying window itself - the one that allows you to flip between the back and front of study cards in a study deck.

## Class Diagram
![Class Diagram](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Architecture/diagram/Class%20Diagram.png)

![Class Diagram 2](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Architecture/diagram/Class%20Diagram%20(2).png)

The above is a class diagram depicting the major classes in the overarching system. Take notice that, even though `util` is depicted, there is no linkage between it and other classes, since it only provides reference functions.
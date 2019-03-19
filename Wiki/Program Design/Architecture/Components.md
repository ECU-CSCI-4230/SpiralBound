## Components
In the SpiralBound system, there are three overarching, logical components:
- Calendar
- Notebook
- Flash Card / Study Tool

It's important to note that these three, major components are all a part of a whole - the `MainWindow` class.

### Calendar
The calendar is a central place for keeping track of upcoming events on a monthly basis. It consists of the calendar itself in `MainWindow`, but also a few prompt classes that allow insertion, transfiguration, and removal of events.

### Notebook
The notebook is important for taking notes in a markdown format, with a text editor to the right that will update actively and show how your actual notes look (such as for printing). It's comprised of a small error prompt for trying to delete a single page/section, as well as a few classes that store the Notebook's data.

### Study Tool
The study utility is where flash cards are made for studying the content that you take notes for. It consists of a deck structure, where each deck is for a specific class and consists of cards that have fronts and backs. The brunt of the GUI is in `MainWindow`, with a few prompts, such as with the calendar, to add and remove cards.
## Data Saving and Loading
The application handles three significant sets of data:
- Calendar events, in the form of dates, times, and names
- Study cards, in the form of deck name, front, and backs
- Notebook notes, in the form of sections, where each section contains pages

There are two directories that are checked for on startup, created if they do not exist:
- `<home>/.spiralbound/books/`, where books are stored
- `<home>/.spiralbound/backup/`, where backups are stored during saving

When the program attempts to load information, it stores information preliminarily in a list of Event and Deck structures. It only updates the interface with this information when everything has successfully been read in. If a failure occurs, then the data is simply discarded from the memory, leaving the present-loaded notebook intact.

When the program attempts to save information, it generates a backup in the aforementioned directory, then tries to write all the files to the disk. Should any of these files fail to be written, such as being unable to be open or otherwise, then the saved content is destroyed by copying the backup back to the original directory, leaving the contents unchanged.

### Restrictions
When the user chooses to load a notebook, there are no restrictions. A file prompt opens, defaulting to the location `<home>/.spiralbound/books/`, and they are allowed to open a notebook from any directory on their machine or external devices; however, when they choose to save a file, they will be sandboxed to the aforementioned directory. In order to save a notebook outside of this directory, they must use the _Export_ utility in File > Export, and select the directory of which they want the book to be saved to. _(This will not update the program to save there; it will still use the sandboxed location on-disk.)_

### Data Format
Data is saved in the following, overarching form to the disk:
```
<Notebook root directory>
- about.txt
- cal.txt
- /study/
  - 1.csv
  - 2.csv
  - ...
- /sections/
  - 1
    - about.txt
    - pg-01.txt
    ...
  - ...
```
The notebook's root directory is a subdirectory in `<home>/.spiralbound/books`, and stores all information. It contains the following files:
- `about.txt`, or the name, author, and date of notebook creation, as well as the number of study decks that are in the book itself
- `cal.txt`, or calendar events, where events are stored in the form of `<date>\n<name>\n<time>`, where `\n` represents a linebreak

It contains the following directories:
- `/study/`, or a list of CSV files that store the study decks, where the first line is the name of the deck, and the following lines are in the form `<n>,<front>,<back>`. The first parameter specifies where to split the front and back, not including the first comma and the value of n itself.
  - For example, `4,CSS,Style Sheets` says to split four characters in, starting from the 'C'; as such, it will be split into **'CSS'** and **'Style Sheets'**
- `/sections/`, or the content of the notebook itself, where each section is a subdirectory with the following contents:
  - `about.txt`, or the name, color, and section summary
  - `page-<n>.txt`, or text files specifying the page name, creation date, and content for the section in question
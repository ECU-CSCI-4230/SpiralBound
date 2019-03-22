## Purpose of Test
**Date**: 21-22 March 2019

The following artifacts are from the overnight development of the loading feature for the notebook, calendar, and flash card data. Various issues were encountered, and a few crashes fixed along the way. Due to a lack of ease with unit testing, the following artifacts are console output or code snippets, taken at the time of failed tests and success.

### Loading Card Information
```
"Software Engineering" "L,Hy" "ertext Markup Language - used for webpage design"
"Software Engineering" "S,C" "scading Style Sheets - used for styling HTML pages"
"Software Engineering" "y,Java" "cript library for dynamically changing page content"
"Web Applications" "t,S" "urce code version control management system"
"Web Applications" "b,Webs" "te that uses git for source code version control"
"Web Applications" "ng,The process of de" "igning, programming, and making software"
```

This test failed because of an error in computing what index to separate the card string from (when trying to parse `<n>` from a card's information).

```
"Software Engineering" "HTML" "Hypertext Markup Language - used for webpage design"
"Software Engineering" "CSS" "Cascading Style Sheets - used for styling HTML pages"
"Software Engineering" "jQuery" "Javascript library for dynamically changing page content"
"Web Applications" "Git" "Source code version control management system"
"Web Applications" "GitHub" "Website that uses git for source code version control"
"Web Applications" "Software Engineering" "The process of designing, programming, and making software"
```

### Loading Calendar Events
```C++
while(!cal.atEnd()) {
    QStringList event = cal.readLine().split(",");
    emit loadEvent(event.takeAt(1), QString("%1%2").arg(event.takeAt(0)).arg(event.takeAt(2)));
}
```

The following code snippet failed to properly load the calendar events, where `cal` is a QTextStream being used to read data from the calendar events CSV. This was due to the usage of the function `takeAt()` making changes to the list `event`, generating an index out of range error.

```C++
while(!cal.atEnd()) {
    QStringList event = cal.readLine().split(",");
    emit loadEvent(event.at(1), QString("%1 %2").arg(event.at(0)).arg(event.at(2)));
}
```

The above code was what was required to properly split calendar events.

### Loading Sections and Pages
`"F:/Academic/Source/SpiralBound/SampleNotebook/sections/./about.txt"`

This is not the correct location of the 'about' file for one of the sample sections. This occured due to no filter being set on the QDir instance being used to sift through each of the sections in a for loop.

**Test 2**: Pages wouldn't load - instead, the error prompt for a bad page arose. This happened due to the filename not being constructed properly for opening.

**Test 3**: Pages properly loaded; however, sections loaded with their summary files as their own pages. This is due to filename comparisons not being properly executed. The full name of a file was being compared against the name we wanted to ignore - 'about.txt'. This was fixed by splitting the full name at '/', and comparing the last entry of the resulting QString list to the filename.
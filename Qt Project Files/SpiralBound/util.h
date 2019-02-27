#ifndef UTIL_H
#define UTIL_H

// Author:       Matthew Morgan
// Init date:    02-23-2019
// Last updated: 02-25-2019
/** find(str, c, strlen) searches for a character, c, in the string str, and
  * returns the first index that it encounters the character at. If there is
  * no occurence found, -1 is returned. strlen is the length of the string
  * being searched. */

int find(char* str, char c, int strlen) {
    for(int i=0; i<strlen; i++)
        if (str[i] == c) { return i; }
    return -1;
}

// Author:       Matthew Morgan
// Init date:    02-23-2019
// Last updated: 02-25-2019
/** findr(str, c, strlen) searches for a character, c, from the end of the
  * string str, and returns the first index it encounters the character at.
  * If there is no occurence, then -1 is returned. strlen is the length of
  * the string, and in turn the starting position to search from. */

int findr(char* str, char c, int strlen) {
    for(int i=strlen-1; i>0; i--)
        if (str[i] == c) { return i; }
    return -1;
}

#endif // UTIL_H

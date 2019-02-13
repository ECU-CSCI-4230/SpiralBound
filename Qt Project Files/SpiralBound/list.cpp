#include "list.h"
#include <QString>
#include <iostream>
using namespace std;

// Author:
// Init date:
// Last Updated:
template <class T>
List<T>::List()
{
    data = NULL;
    nxt = NULL;
}

// Author:
// Init date:
// Last Updated:
template <class T>
List<T>::List(T dat)
{
    data = dat;
    nxt = NULL;
}

// Author:
// Init date:
// Last Updated:
template <class T>
List<T>::~List()
{

}

// Author:
// Init date:
// Last Updated:
template <class T>
void List<T>::add(T dat, int index)
{

}

// Author:
// Init date:
// Last Updated:
template <class T>
void List<T>::add(T dat)
{

}

// Author:
// Init date:
// Last Updated:
template <class T>
T List<T>::get(int index)
{
    return NULL;
}

// Author:
// Init date:
// Last Updated:
template <class T>
T List<T>::remove(int index)
{
    return NULL;
}

// Author:
// Init date:
// Last Updated:
template <class T>
void List<T>::clear()
{

}

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
template <class T>
int List<T>::length()
{
    if (nxt == NULL) { return 0; }
    else { return 1 + length(nxt); }
}

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
template <class T>
bool List<T>::isEmpty() { return nxt != NULL; }

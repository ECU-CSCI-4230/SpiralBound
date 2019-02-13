#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
    private:
        typedef List Node;

        // data is the data item for the current List node
        // nxt is a pointer to the next node in the list
        T data;
        Node* nxt;

        /** List(dat) constructs a node with the given data. */
        List(T dat);

    public:
        List();
        ~List();

        /** add(dat, index) inserts the provided data, 'dat,' into the list at
          * the specified index. If the index is out of bounds, then NULL is
          * returned. */
        void add(T dat, int index);

        /** add(dat) inserts the provided data, 'dat,' into the list at the
          * end of the list. */
        void add(T dat);

        /** get(index) retrieves an item at the specified index. */
        T get(int index);

        /** remove(index) removes the item at the specified index, returning it
          * for future operations. */
        T remove(int index);

        /** clear() removes all items in the list. **/
        void clear();

        /** isEmpty() returns true if the list has no items in it. **/
        bool isEmpty();

        /** length() returns the number of items in the list. */
        int length();
};

#endif // LIST_H

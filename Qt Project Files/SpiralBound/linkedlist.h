#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
private:
    struct node
    {
        T data;
        node * next;
    } *head;

public:
    LinkedList();
    ~LinkedList();
    void add(T d);
    void remove(T d);
    void clear();
    void makeCircular();
    bool isCircular();
    void display(const char* s);
    T get_index_item(int i);
};
#endif // LINKEDLIST_H

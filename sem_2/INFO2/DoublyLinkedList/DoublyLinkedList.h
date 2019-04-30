#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Item.h"

template <class T> class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        Item<T>* head();
        bool isEmpty();
        Item<T>* first();
        Item<T>* last();
        void moveAfter(Item<T> *b, Item<T> *a);
        void moveToFront(Item<T> *b);
        void moveToBack(Item<T> *b);
        void removeItem(Item<T> *b);
        void popFront();
        void popBack();
        Item<T>* insertAfter(T new_element, Item<T> *a);
        Item<T>* insertBefore(T new_element, Item<T> *b);
        void pushFront(T new_element);
        void pushBack(T new_element);
        Item<T>* findElement(T new_element);
        int getSize();
		void bubbleSort();
        void mergeSort();
    private:
        Item<T>* h;
        void splice(Item<T> *a, Item<T> *b, Item<T> *t);
		void mergeSort_sort(DoublyLinkedList<T> * unsorted_list);
        void mergeSort_merge(DoublyLinkedList<T>* unsorted_list, DoublyLinkedList<T>* l, DoublyLinkedList<T>* r);
};

#endif // DOUBLYLINKEDLIST_H

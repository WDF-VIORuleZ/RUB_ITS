#ifndef ITEM_H
#define ITEM_H

template <class T> class Item
{
    public:
        Item();
        Item *prev;
        Item *next;
        T element;
};

template <class T> Item<T>::Item()
{
    prev= this;
    next= this;
}

#endif // ITEM_H

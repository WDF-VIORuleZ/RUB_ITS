#include "DoublyLinkedList.h"

template <class T> DoublyLinkedList<T>::DoublyLinkedList()
{
    h = new Item<T>();
    h->next = h;
    h->prev = h;
}

template <class T> DoublyLinkedList<T>::~DoublyLinkedList()
{
	Item<T>* p_run = this->first();

	//iterate through list and delete every element
	while (p_run != this->h)
	{
		p_run = p_run->next;
		delete p_run->prev;
	}


    delete h;
}

template <class T> void DoublyLinkedList<T>::splice(Item<T> *a, Item<T> *b, Item<T> *t)
{
	//slice
	Item<T>* p_ap = a->prev;
	Item<T>* p_bn = b->next;
	p_ap->next = p_bn;
	p_bn->prev = p_ap;

	//insert
	Item<T>* p_tn = t->next;
	b->next = p_tn;
	a->prev = t;
	t->next = a;
	p_tn->prev = b;

}

template <class T> Item<T>* DoublyLinkedList<T>::head()
{
	return this->h;
}

template <class T> bool DoublyLinkedList<T>::isEmpty()
{
	return (this->h->next == this->head());
}

template <class T> Item<T>* DoublyLinkedList<T>::first()
{
	return this->h->next;
}

template <class T> Item<T>* DoublyLinkedList<T>::last()
{
	return this->h->prev;
}

template <class T> void DoublyLinkedList<T>::moveAfter(Item<T> *b, Item<T> *a)
{
	this->splice(b, b, a);
}

template <class T> void DoublyLinkedList<T>::moveToFront(Item<T> *b)
{
	this->moveAfter(b, this->head());
}

template <class T> void DoublyLinkedList<T>::moveToBack(Item<T> *b)
{
	this->moveAfter(b, this->last());
}

template <class T> void DoublyLinkedList<T>::removeItem(Item<T> *b)
{
	if (this->isEmpty())
		return;

	if (b == this->h)
	{	//just relocate this->last() if slicing head
		h->next->prev = h->prev;
		this->h = b->next;
	}
	else
	{	// slice out by relocating pointer
		b->next->prev = b->prev;
		b->prev->next = b->next;
	}

	//free memory
	delete b;
	return;
}

template <class T> void DoublyLinkedList<T>::popFront()
{
	this->removeItem(this->first());
}

template <class T> void DoublyLinkedList<T>::popBack()
{
	this->removeItem(this->last());
}

template <class T> Item<T>* DoublyLinkedList<T>::insertAfter(T new_element, Item<T> *a)
{
	//init new item from stack
	Item<T>* p_tmp = new Item<T>();
	p_tmp->element = new_element;

	//insert in list
	this->moveAfter(p_tmp, a);

	return p_tmp;
}

template <class T> Item<T>* DoublyLinkedList<T>::insertBefore(T new_element, Item<T> *b)
{
	return this->insertAfter(new_element, b->prev);
}

template <class T> void DoublyLinkedList<T>::pushFront(T new_element)
{
	this->insertAfter(new_element, this->head());
}

template <class T> void DoublyLinkedList<T>::pushBack(T new_element)
{
	this->insertAfter(new_element, this->last());
}

template <class T> Item<T>* DoublyLinkedList<T>::findElement(T new_element)
{
	//init run variable
	Item<T>* p_tmp = this->first();
	h->element = new_element;

	//check through list by itration
	while (p_tmp->element != new_element)
		p_tmp = p_tmp->next;

	//return pointer if found, otherwise nullptr if reached head
	return p_tmp == this->h ? nullptr : p_tmp;
}

template <class T> int DoublyLinkedList<T>::getSize()
{
	//init run variable
	Item<T>* p_tmp = this->first();

	//iterate through list and count
	int ctr = 0;
	while (p_tmp != this->h) 
	{
		p_tmp = p_tmp->next;
		ctr++;
	}

	return ctr;
}


// you can ignore the functions below this line 
// -----------------------------------------------------------------------

template <class T> void DoublyLinkedList<T>::bubbleSort()
{
	// not part of this exercise
}

template <class T> void DoublyLinkedList<T>::mergeSort()
{
    // not part of this exercise
}

template <class T> void DoublyLinkedList<T>::mergeSort_sort(DoublyLinkedList<T> * unsorted_list)
{
	// not part of this exercise
}

template <class T> void DoublyLinkedList<T>::mergeSort_merge(DoublyLinkedList<T>* unsorted_list, DoublyLinkedList<T>* l, DoublyLinkedList<T>* r)
{
	// not part of this exercise
}

#if !__has_include ("aircraft.h")
	template class DoublyLinkedList<int>;
#endif

#if __has_include ("aircraft.h")
	#include "aircraft.h"
	template class DoublyLinkedList<aircraft*>;
#endif

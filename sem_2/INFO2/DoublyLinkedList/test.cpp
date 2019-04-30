
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

#define TEST_LENGTH 7
int test_1[TEST_LENGTH] = {27,53,89,11,123,94,37};
int test_2[TEST_LENGTH] = {27,37,53,89,11,123,94};
int test_3[TEST_LENGTH] = {94,27,37,53,89,11,123};
int test_4[TEST_LENGTH-1] = {37,53,89,11,123,94};
int test_5[TEST_LENGTH-2] = {53,89,11,123,94};
int test_6[TEST_LENGTH-3] = {53,89,11,123};
int test_7[TEST_LENGTH-2] = {53,55,89,11,123};
int test_8[TEST_LENGTH-1] = {91,53,55,89,11,123};
int test_9[TEST_LENGTH] = {21,91,53,55,89,11,123};
int test_10[TEST_LENGTH+1] = {21,91,53,55,89,11,123,22};

//0 - fail; 1 - success
int compare_list_test_case(DoublyLinkedList<int> *l, int* test, int len)
{
    int j = 0;
    for (Item<int> *i = l->first() ; i != l->head() ; i = i->next)
    {
        if(i->element != test[j])
        {
            cout << i->element << " " << test[j] << endl;
            return 0;
        }
        j++;
    }
    return j == len;
}

bool compare_list_size(DoublyLinkedList<int> *l)
{
    int j = 0;
    for (Item<int> * i = l->first(); i != l->head() ; i = i->next)
    {
        j++;
    }
    return l->getSize() == j;
}

bool find_element(DoublyLinkedList<int> *l, int x)
{
    Item<int>* f = l->findElement(x);

    if (f == NULL) return false;
    return f->element == x;
}

void print_list(DoublyLinkedList<int> *l)
{
    for (Item<int> * i = l->first(); i != l->head() ; i = i->next)
    {
        cout << i->element << " ";
    }
    cout << endl;
}


void test_list(DoublyLinkedList<int> *l)
{
    int success = 1;

    success *= compare_list_size(l);
    if(!success)
    {
        cout << "Error in size()" << endl;
        print_list(l);
        return;
    }

    // test isEmpty()
    success *= (l->isEmpty() == true);

    // test pushBack()
    for (int i = 0; i<TEST_LENGTH; i++)
    {
        l->pushBack(test_1[i]);
    }

    // test isEmpty()
    success *= (l->isEmpty() == false);
    if(!success)
    {
        cout << "Error in isEmpty()" << endl;
        print_list(l);
        return;
    }

    success *= compare_list_test_case(l, test_1, TEST_LENGTH);
    if(!success)
    {
        cout << "Error in pushBack()" << endl;
        print_list(l);
        return;
    }

    success *= compare_list_size(l);
    if(!success)
    {
        cout << "Error in size()" << endl;
        print_list(l);
        return;
    }

    //test moveAfter()
    l->moveAfter(l->last(), l->first());
    success *= compare_list_test_case(l, test_2, TEST_LENGTH);
    if(!success)
    {
        cout << "Error in moveAfter()" << endl;
        print_list(l);
        return;
    }


    //test moveToFront()
    l->moveToFront(l->last());
    success *= compare_list_test_case(l, test_3, TEST_LENGTH);
    if(!success)
    {
        cout << "Error in moveToFront()" << endl;
        print_list(l);
        return;
    }


    //test moveToBack()
    l->moveToBack(l->first());
    success *= compare_list_test_case(l, test_2, TEST_LENGTH);
    if(!success)
    {
        cout << "Error in moveToBack()" << endl;
        print_list(l);
        return;
    }


    //test removeItem()
    l->removeItem(l->first());
    success *= compare_list_test_case(l, test_4, TEST_LENGTH-1);
    if(!success)
    {
        cout << "Error in remove()" << endl;
        print_list(l);
        return;
    }

    success *= compare_list_size(l);
    if(!success)
    {
        cout << "Error in size()" << endl;
        print_list(l);
        return;
    }

    //test popFront()
    l->popFront();
    success *= compare_list_test_case(l, test_5, TEST_LENGTH-2);
    if(!success)
    {
        cout << "Error in popFront()" << endl;
        print_list(l);
        return;
    }

    success *= compare_list_size(l);
    if(!success)
    {
        cout << "Error in size()" << endl;
        print_list(l);
        return;
    }

    //test popBack()
    l->popBack();
    success *= compare_list_test_case(l, test_6, TEST_LENGTH-3);
    if(!success)
    {
        cout << "Error in popBack()" << endl;
        print_list(l);
        return;
    }

    success *= compare_list_size(l);
    if(!success)
    {
        cout << "Error in size()" << endl;
        print_list(l);
        return;
    }

    //test insertAfter()
    l->insertAfter(55, l->first());
    success *= compare_list_test_case(l, test_7, TEST_LENGTH-2);
    if(!success)
    {
        cout << "Error in insertAfter()" << endl;
        print_list(l);
        return;
    }


    //test insertBefore()
    l->insertBefore(91, l->first());
    success *= compare_list_test_case(l, test_8, TEST_LENGTH-1);
    if(!success)
    {
        cout << "Error in insertBefore()" << endl;
        print_list(l);
        return;
    }

    //test pushFront()
    l->pushFront(21);
    success *= compare_list_test_case(l, test_9, TEST_LENGTH);
    if(!success)
    {
        cout << "Error in pushFront()" << endl;
        print_list(l);
        return;
    }

    success *= find_element(l, 21);
    if(!success)
    {
        cout << "Error in findElement()" << endl;
        print_list(l);
        return;
    }

    //test pushBack()
    l->pushBack(22);
    success *= compare_list_test_case(l, test_10, TEST_LENGTH+1);
    if(!success)
    {
        cout << "Error in pushBack()" << endl;
        print_list(l);
        return;
    }

    success *= find_element(l, 22);
    if(!success)
    {
        cout << "Error in find()" << endl;
        print_list(l);
        return;
    }

    success *= !find_element(l, 87);
    if(!success)
    {
        cout << "Error in findElement()" << endl;
        print_list(l);
        return;
    }

    if(success)
        cout << "All tests passed." << endl;
}

int main()
{
    DoublyLinkedList<int> l;
    test_list(&l);
    return 0;
}


#include <iostream>
#include "calculator.h"

using namespace std;

void test_calculator(Calculator* c)
{
    if(c->pred(5) != 4)
    {
        cout << "pred incorrect" << endl;
        return;
    }

    if(c->add(5,-8) != -3)
    {
        cout << "add incorrect" << endl;
        return;
    }

    if(c->sub(0,-1) != 1)
    {
        cout << "sub incorrect" << endl;
        return;
    }

    if(c->mul(3,-4) != -12)
    {
        cout << "mul incorrect" << endl;
        return;
    }

    if(c->mul(0,-4) != 0)
    {
        cout << "mul incorrect" << endl;
        return;
    }

    if(c->div(6,3) != 2)
    {
        cout << "div incorrect" << endl;
        return;
    }

    if(c->div(7,9) != 0)
    {
        cout << "div incorrect" << endl;
        return;
    }

    if(c->exp(2,3) != 8)
    {
        cout << "exp incorrect" << endl;
        return;
    }

    cout << "All tests passed." << endl;
}

int main()
{
	Calculator c;
    test_calculator(&c);
    /*
    cout << "output: ";
    cout << c.add(5, 2) << endl;
    cout << c.add(5, -3) << endl;
    cout << c.sub(5, 4) << endl;
    */
	return 0;
}

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    public:
        Calculator();
        ~Calculator();
        int succ(int x);
        int neg(int x);

        int pred(int x);
        int add(int x, int y);
        int sub(int x, int y);
        int mul(int x, int y);
        int div(int x, int y);
        int exp(int x, int y);
};

#endif //CALCULATOR_H

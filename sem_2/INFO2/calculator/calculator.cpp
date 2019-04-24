

    #include "calculator.h"
     
    Calculator::Calculator()
    {
    }
     
    Calculator::~Calculator()
    {
    }
     
    int Calculator::succ(int x)         //x++
    {
    	return ++x;
    }
     
    int Calculator::neg(int x)          //-x
    {
    	return -x;
    }
     
    // define the following functions using only: "succ", "neg" and functions defined above (e.g. you can use "add" for "sub").
     
     
    int Calculator::pred(int x)         //x--
    {
    	
    	return neg(succ(neg(x)));
    }
     
    int Calculator::add(int x, int y)   //x+y
    {
        /*
            loop increase / decrease x depending on the sign of y
        */

    	for (int i = y; y != 0; y = y < 0 ? succ(y) : pred(y))
    		x = y < 0 ? pred(x) : succ(x);
    	
    	return x;
    }
     
    int Calculator::sub(int x, int y)   //x-y
    {
        /*
            negate x, add y and return negated again
        */

    	x = neg(x);                     
    	x = add(x,y);
     
    	return neg(x);
    }
     
    int Calculator::mul(int x, int y)   //x*y
    {
    	if(x == 0 || y == 0)            //multiplication with 0 equals 0
    		return 0;
     
    	int unsig = y < 0 ? neg(y) : y, res = x;
     
    	for(int i = 1; i < unsig; i = succ(i))
    		res = add(res,x);
     
    	return y < 0 ? neg(res) : res;
    }
     
    int Calculator::div(int x, int y)   // x/y
    {
    	if (y == 0)                     //return 0 when the divisor is 0
    		return 0;
     
    	int unsig = y < 0 ? neg(y) : y; //unsigned value of y
    	int qut = 0;                    //quotient
    	int rem = x < 0 ? neg(x) : x;   //unsigned remainder
     
    	while (rem >= unsig)            //subtract till remainder is less than divisor
    	{
    		qut = succ(qut);
    		rem = sub(rem,unsig);
    	}
    	
    	return y < 0 || x < 0 ? neg(qut) : qut;
    }
     
    int Calculator::exp(int x, int y)   //x^y
    {
    	if (y < 0)                      // cannot divide by zero
    		return 0;
    	if (y == 0)                     //per definition x^0 = 1
    		return 1;
     
    	int res = x;

    	for (int i = 1; i < y; i = succ(i))
    		res = mul(res,x);
     
    	return res;
    }


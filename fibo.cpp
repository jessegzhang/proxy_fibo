#include "fibo.h"
#include <memory>

//Fibo Default Constructor
//pushes back 0 and 1, the first two ints of Fibo
Fibo::Fibo()
{
	_fiboNums.push_back(0);
	_fiboNums.push_back(1);
}

//Class RealFibo function defintion of calculate
//finds the amount of calculations done need to get the nth fibonacci number
//then calculates it pushing each number into the vector
int RealFibo::calculate(int n)
{
	int loopCount = n - _fiboNums.size();
	for (int i = 0; i < loopCount; i++)
	{
		_fiboNums.push_back(_fiboNums[_fiboNums.size() - 1] + _fiboNums[_fiboNums.size() - 2]);
	}
	return _fiboNums[n - 1];
}

//Class RealFibo function defintion of calculate
//finds the amount of calculations done need to get the nth fibonacci number
//checks to see if the fibonacci number is stored in the vector before creating an instance of RealFibbo
int ProxyFibo::calculate(int n)
{
	if (n<0)
	{
		throw;
	}
	if (_fiboNums.size() >= n)
	{
		return _fiboNums[n - 1];
	}
	else
	{
		std::unique_ptr<Fibo> fiboTemp(new RealFibo);
		int val = fiboTemp->calculate(n);
		_fiboNums = fiboTemp->_fiboNums;
		return val;
	}
}


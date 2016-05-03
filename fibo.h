#ifndef FIBO_H
#define FIBO_H
#include <vector> //include for vector

// *********************************************************************
// class Fibo - Class definition
// *********************************************************************

// Class Fibo
// Base Class Fibo that RealFibo and ProxyFibo inherits from
class Fibo
{
public:
	Fibo();
	virtual int calculate(int n)=0;
	std::vector<int> _fiboNums;
};

// *********************************************************************
// class RealFibo - Class definition
// *********************************************************************

// Class RealFibo
// inherits from Class Fibo and overwrites calculate function
class RealFibo : public Fibo
{
public:
	int calculate(int n);
};

// *********************************************************************
// class ProxyFibo - Class definition
// *********************************************************************

// Class ProxyFibo
// inherits from Class Fibo and overwrites calculate function
class ProxyFibo : public Fibo
{
public:
	int calculate(int n);
};


#endif
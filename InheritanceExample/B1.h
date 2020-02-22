#pragma once
#include <iostream>
using namespace std;
class B1
{
	int a1;
public:
	B1() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B1(int x) : B1() { a1 = x; }
	~B1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class B2
{
	int a2;
public:
	B2() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B2(int x) : B2() { a2 = x; }
	~B2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D1: public B1
{
	int b;
public:
	D1(int x,int y) : B1(y) 
	{ 
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D2 : private D1, private B2
{
	int c;
public:
	D2(int x, int y, int z, int i) : D1(y, z), B2(i)
	{
		c = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D3 : public D2
{
	int d;
public:
	D3(int x, int y, int z, int i) : D2(x, y, z, i)
	{
		d = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

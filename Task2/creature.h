#pragma once
#include <iostream>
#include <string>
using namespace std;
class creature
{
private:
	string title;
	double mass;
protected:
	creature() :mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) : title(_title), mass(_mass) {}
	virtual ~creature() { cout << "creature deleted" << endl << endl; }
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }
public:
	void print() const 
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")" << endl;
	}
	double get_mass() const 
	{
		return mass;
	}
};
class animal :public creature
{
private:
	double speed;
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const string& _title, double _mass, double _speed) : creature(_title, _mass), speed(_speed) {}
	double get_speed() const
	{
		return speed;
	}
	~animal() { cout << "animal deleted" << endl; }
protected:
	void _print() const 
	{
		creature::_print();
		cout << ", speed: " << speed;
	}

};
class bird : public virtual animal
{
private:
	double topfly;
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly) : animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { cout << "bird deleted" << endl; }
protected:
	void _print() const
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};
class fish : public animal
{
private:
	double maxdeep;
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep) : animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { cout << "fish deleted" << endl; }
protected:
	void _print() const
	{
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};
class predator : public virtual animal 
{
protected:
	predator() {}
public:
	~predator() {}
	virtual bool hunt(const animal& obj) = 0;
};
class eagle : public bird, public predator
{
public:
	eagle() :bird() {}
	eagle(const eagle& obj) : bird(obj),animal(obj) {}
	eagle(double _mass, double _speed, double _topfly) : bird("", 0, 0, 0), animal("Îð¸ë", _mass, _speed) {}
	bool hunt(const animal& obj)
	{
		return obj.get_mass() < get_mass() && obj.get_speed() < get_speed();
	}
};

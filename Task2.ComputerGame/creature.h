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
class mythical :public animal
{
private:
	double power;
public:
	mythical() : animal() {}
	mythical(const mythical& obj) : animal(obj), power(obj.power) {}
	mythical(const string& _title, double _mass, double _speed, double _power) : animal(_title, _mass, _speed), power(_power) {}
	double get_power() const
	{
		return power;
	}
	~mythical() { cout << "mythical deleted" << endl; }
protected:
	void _print() const
	{
		animal::_print();
		cout << ", power: " << power;
	}

};
class biological :public animal
{
private:
	double strength;
public:
	biological() : animal() {}
	biological(const biological& obj) : animal(obj), strength(obj.strength) {}
	biological(const string& _title, double _mass, double _speed, double _strength) : animal(_title, _mass, _speed), strength(_strength) {}
	double get_strength() const
	{
		return strength;
	}
	~biological() { cout << "biological deleted" << endl; }
protected:
	void _print() const
	{
		animal::_print();
		cout << ", strength: " << strength;
	}
};
class magic_being :public mythical
{
private:
	double incantation_knowledge;
public:
	magic_being() : mythical() {}
	magic_being(const magic_being& obj) : mythical(obj), incantation_knowledge(obj.incantation_knowledge) {}
	magic_being(const string& _title, double _mass, double _speed, double _power, double _incantation_knowledge) : mythical(_title, _mass, _speed, _power), incantation_knowledge(_incantation_knowledge) {}
	double get_knowledge() const
	{
		return incantation_knowledge;
	}
	~magic_being() { cout << "magic_being deleted" << endl; }
protected:
	void _print() const
	{
		mythical::_print();
		cout << ", incantation_knowledge: " << incantation_knowledge;
	}
};
class human_being :public biological
{
private:
	double mind;
public:
	human_being() : biological() {}
	human_being(const human_being& obj) : biological(obj), mind(obj.mind) {}
	human_being(const string& _title, double _mass, double _speed, double _strength, double _mind) : biological(_title, _mass, _speed, _strength), mind(_mind) {}
	double get_mind() const
	{
		return mind;
	}
	~human_being() { cout << "human_being deleted" << endl; }
protected:
	void _print() const
	{
		biological::_print();
		cout << ", mind: " << mind;
	}
	virtual bool move(const human_being& obj) = 0;
	virtual bool draw(const human_being& obj) = 0;
};
class magic_thing :public virtual magic_being
{
private:
	double durability;
public:
	magic_thing() : magic_being() {}
	magic_thing(const magic_thing& obj) : magic_being(obj), durability(obj.durability) {}
	magic_thing(const string& _title, double _mass, double _speed, double _power, double _incantation_knowledge, double _durability) : magic_being(_title, _mass, _speed, _power, _incantation_knowledge), durability(_durability) {}
	double get_durability() const
	{
		return durability;
	}
	~magic_thing() { cout << "magic_thing deleted" << endl; }
protected:
	void _print() const
	{
		magic_being::_print();
		cout << ", durability: " << durability;
	}
};
class homo_sapiens :public virtual human_being
{
private:
	double hope;
public:
	homo_sapiens() : human_being() {}
	homo_sapiens(const homo_sapiens& obj) : human_being(obj), hope(obj.hope) {}
	homo_sapiens(const string& _title, double _mass, double _speed, double _strength, double _mind, double _hope) : human_being(_title, _mass, _speed, _strength, _mind), hope(_hope) {}
	double get_hope() const
	{
		return hope;
	}
	virtual bool move(const human_being& obj) {
		return obj.get_speed() > get_speed() && obj.get_strength() > get_strength();
	}
	virtual bool draw(const human_being& obj){
		return obj.get_mind() > get_mind() && obj.get_strength() > get_strength();
	}
	virtual bool powermind(const animal& obj) {
		return obj.get_mass() > get_mass() && obj.get_speed() > get_speed();
	}
	~homo_sapiens() { cout << "homo_sapiens deleted" << endl; }
protected:
	void _print() const
	{
		human_being::_print();
		cout << ", hope: " << hope;
	}
};
class superman :public virtual animal {
protected:
	superman() {}
public:
	~superman() {}
	virtual bool powermind(const animal& obj) = 0;
};
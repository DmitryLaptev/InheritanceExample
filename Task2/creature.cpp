#include "creature.h"
#include <iostream>
using namespace std;
int main() 
{
	setlocale(0, "Rus");
	bird raven("������", 0.3, 10, 0.1);
	//eagle eagle1(1, 100, 1);
	fish hammerhead("����-�����", 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	predator& eagle1 = *new eagle(1, 100, 1);
	cout << "Eagle vs raven: " << eagle1.hunt(raven) << endl;
	cout << "Eagle vs hammerhead: " << eagle1.hunt(hammerhead) << endl;
	cout << endl;
	delete& eagle1;
	return 0;
}
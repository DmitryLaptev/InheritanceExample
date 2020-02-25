#include "creature.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(0, "Rus");
	homo_sapiens human("Guman", 58, 20, 54, 126, 100);
	magic_being unicorn("Единорог - единый рог", 60, 65, 78, 54);
	human.print();
	unicorn.print();
	human_being& superhuman = *new homo_sapiens("Супермен", 66, 30, 55, 128, 5);
	superhuman.print();
	cout << "human vs superhuman " << human.move(superhuman) << endl;
	cout << "human vs superhuman " << human.draw(superhuman) << endl;
	cout << "human vs superhuman " << human.powermind(superhuman) << endl;
	return 0;
}
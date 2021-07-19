#include <iostream>
#include "Endll.h"
#include "Player.h"
#include "House.h"

using namespace std;

bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

int main()
{
	string val;
	do {
		cin >> val;
		if (isNumber(val)) {
			break;
		}
		else {
			cerr << "Incorrect int inserted" << endll;
		}
	}
	while (true);
	
	int intVal = atoi(val.c_str());
	cout << "Number is " << intVal << endll;

	Card c(Suit::CLUBS, CardValue::FOUR);
	cout << c;

}
#include <iostream>
#include "Date.h"
#include "Deck.h"
#include "Game.h"

using namespace std;

unique_ptr<Date>& dateCompare(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
	return *date1.get() > *date2.get() ? date1 : date2;
}

void play(string name) {
	vector<string> v = { name };
	Game game(v);
	cout << game.play() << endl;
}

bool doContinue() {
	string answer = "";
	while (answer != "true" && answer != "false") {
		cout << "Continue?";
		cin >> answer;
	}
	return answer == "true" ? true : false;
}

int main()
{
	//1 task
	{
		unique_ptr<Date> today = make_unique<Date>(Date(21, 07, 2021));
		unique_ptr<Date> date;
		today->getDay();
		today->getMonth();
		today->getYear();
		cout << *today.get();

		date = move(today);

		cout << *date;
		cout << (today.get());
	}

	//2 task
	{
		unique_ptr<Date> date1 = make_unique<Date>(Date(1, 1, 1));
		unique_ptr<Date> date2 = make_unique<Date>(Date(21, 07, 2021));
		cout << *dateCompare(date1, date2).get();
	}

	do {
		play("Andrei");
	} 	
	while (doContinue());
}
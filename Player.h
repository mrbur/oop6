#pragma once
#include "GenericPlayer.h"

class Player : virtual public GenericPlayer {
	public:
		Player(string name) : GenericPlayer(name) {
		}
		virtual bool isHitting() override {
			string answer = "";
			while (answer != "true" && answer != "false") {
				cout << "New card?";
				cin >> answer;
			}
			return answer == "true" ? true : false;
		}

		void win() const {
			cout << name << " You won!";
		}
		void lose() const {
			cout << name << " You lose!";
		}
		void push() const {
			cout << name << " Draw!";
		}
};
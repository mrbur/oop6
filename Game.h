#pragma once
#include <iostream>
#include "Deck.h"
#include "House.h"
#include "Player.h"

using namespace std;

class Game {
private:
	Deck* deck;
	House* dealer = new House;
	vector<Player*> players;
public:
	Game(vector<string> names) {
		deck = new Deck;
		deck->shuffle();
		if ((names).size() > 0) {
			for (auto it = names.begin(); it < names.end(); it++) {
				players.push_back(new Player(*it));
			}
		}
	}
	~Game() {
		for (auto it = players.begin(); it < players.end(); it++) {
			delete *it;
		}
		players.clear();
	}

	string play() {
		for (rsize_t i = 0; i < players.size(); i++) {
			deck->deal(*players[i]);
			deck->deal(*players[i]);

			players[i]->viewStatus();
		}
		deck->deal(*dealer);
		dealer->viewStatus();

		for (rsize_t i = 0; i < players.size(); i++) {
			deck->addltionalCards(*players[i]);
		}

		dealer->flipFirstCard();

		deck->addltionalCards(*dealer);

		string winner = "No winners";
		int maxCount = 0;
		for (rsize_t i = 0; i < players.size(); i++) {
			if (!(players[i])->isBoosted() && maxCount < (players[i])->getValue()) {
				winner = "winner is " + players[i]->getName();
				maxCount = players[i]->getValue();
			}
		}
		if (!(dealer)->isBoosted() && maxCount < (dealer)->getValue()) {
			winner = "winner is " + dealer->getName();
			maxCount = dealer->getValue();
		}

		return  winner + " score=" + to_string(maxCount);
	}

	
};
#pragma once
#include <vector>
#include "Card.h"
#include <cassert>

using namespace std;

class Hand {
protected:
	vector<Card*> cards;
public:
	~Hand() {
		if (cards.size() > 0) {
			clear();
		}
	}
	void add(Card* cardPtr) {
		cards.push_back(cardPtr);
	}
	void clear() {
		assert(cards.size() > 0);
		for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); it++) {
			delete (*it);
		}
		cards.clear();
	}

	int getValue() const {
		int value = 0;
		for (vector<Card*>::const_iterator it = cards.begin(); it != cards.end(); it++) {
			if ((*it)->getValue() != 1) {
				value += (*it)->getValue();
			}
		}
		for (vector<Card*>::const_iterator it = cards.begin(); it != cards.end(); it++) {
			if ((*it)->getValue() == 1) {
				if ((value + 11) >= 21) {
					value += 1;
				}
				else {
					value += 11;
				}
			}
			
		}
		return value;
	}
};
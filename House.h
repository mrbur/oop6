#pragma once
#include "GenericPlayer.h"

class House : virtual public GenericPlayer {
public:
	House() : GenericPlayer("House") {
	}
	virtual bool isHitting() override {
		if (getValue() <= 16) {
			return true;
		}
		return false;
	}
	void flipFirstCard() {
		assert(cards.size() > 0);
		cards[0]->flip();
	}

};
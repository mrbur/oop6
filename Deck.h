#pragma once

#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
private:
	void populate() {
		int i = 0;
		Card *card;
		for (int suit = CLUBS; suit != NONE; suit++)
		{
			for (auto it = cardValuesMap.begin(); it != cardValuesMap.end(); it++)
			{
				card = new Card(static_cast<Suit>(suit), it->first);
				this->cards.push_back(card);
			}
		}
	}
	
	
public:
	Deck() {
		populate();
	}

	void deal(Hand& aHand) {
		Card* card = cards.back();
		aHand.add(card);
		cards.pop_back();
	}

	void addltionalCards(GenericPlayer& aGenerlcPlayer) {
		while (cards.size() > 0 && !aGenerlcPlayer.isBoosted() && aGenerlcPlayer.isHitting())
		{
			deal(aGenerlcPlayer);
			aGenerlcPlayer.viewStatus();
		}
	}

	void shuffle() {
		Card* swapCard;
		size_t randIndex;
		for (size_t i = 0; i < cards.size(); i++) {
			randIndex = rand() % cards.size();
			swapCard = cards[i];
			cards[i] = cards[randIndex];
			cards[randIndex] = swapCard;
		}
	}
};
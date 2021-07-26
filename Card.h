#pragma once
#include <string>
#include <map>

enum Suit {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	NONE
};

enum class CardValue {
	ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13
};

map<CardValue, int> cardValuesMap = { {CardValue::ACE, 1}, {CardValue::TWO, 2}, {CardValue::THREE, 3}, {CardValue::FOUR, 4}, {CardValue::FIVE, 5}, {CardValue::SIX, 6}, {CardValue::SEVEN, 7},
		{CardValue::EIGHT, 8}, {CardValue::NINE, 9}, {CardValue::TEN, 10}, {CardValue::JACK, 10}, {CardValue::QUEEN, 10}, {CardValue::KING, 10} };

class Card {
private:
	Suit suit;
	CardValue cardValue;
	bool position = false;
public:
	Card(Suit suit, CardValue cardValue) : suit(suit), cardValue(cardValue) {
	}

	void flip() {
		position = !position ? true : false;
	}
	int getValue() const {
		return cardValuesMap.at(cardValue);
	}

	bool isFlipped() const {
		return position;
	}

	string getCardData() const {
		string data = "";
		switch (suit)
		{
			case CLUBS:
				data += "CLUBS ";
				break;
			case DIAMONDS:
				data += "DIAMONDS ";
				break;
			case HEARTS:
				data += "HEARTS ";
				break;
			case SPADES:
				data += "SPADES ";
				break;
		}
		return data + to_string(getValue());
	}
};

ostream& operator<< (ostream& os, Card& card) {
	if (!card.isFlipped()) {
		cout << card.getCardData();
	}
	else {
		cout << "XX";
	}
	return os;
}
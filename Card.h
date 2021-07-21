#pragma once

enum Suit {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum CardValue {
	TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10, ACE = 1
};

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
		return cardValue;
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
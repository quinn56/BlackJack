/*
 * deck.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "../inc/Deck.h"
Deck::Deck() {
	for (int i = 1; i < 14; i++) {
		char c;
		switch (i) {
			case 1:
				c = ACE;
				break;
			case 2:
				c = TWO;
				break;
			case 3:
				c = THREE;
				break;
			case 4:
				c = FOUR;
				break;
			case 5:
				c = FIVE;
				break;
			case 6:
				c = SIX;
				break;
			case 7:
				c = SEVEN;
				break;
			case 8:
				c = EIGHT;
				break;
			case 9:
				c = NINE;
				break;
			case 10:
				c = TEN;
				break;
			case 11:
				c = JACK;
				break;
			case 12:
				c = QUEEN;
				break;
			case 13:
				c = KING;
				break;
		}
		for (int j = 0; j < 4; j++) {
			Suits s = NONE;
			switch(j) {
				case 0:
					s = HEARTS;
					break;
				case 1:
					s = SPADES;
					break;
				case 2:
					s = CLUBS;
					break;
				case 3:
					s = DIAMONDS;
					break;
			}
			Card* card = new Card(s, c);
			this->cards.push_back(card);
		}
	}
}

void Deck::print_deck() {
	for (unsigned int i = 0; i < cards.size(); i++)
		cards[i]->print_card();
}

std::vector<Card*> Deck::get_cards() {
	return this->cards;
}

void Deck::delete_card_at(int i) {
	this->cards.erase(this->cards.begin() + i);
}

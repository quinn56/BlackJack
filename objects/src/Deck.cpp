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
				c = 'A';
				break;
			case 2:
				c = '2';
				break;
			case 3:
				c = '3';
				break;
			case 4:
				c = '4';
				break;
			case 5:
				c = '5';
				break;
			case 6:
				c = '6';
				break;
			case 7:
				c = '7';
				break;
			case 8:
				c = '8';
				break;
			case 9:
				c = '9';
				break;
			case 10:
				c = '0';
				break;
			case 11:
				c = 'J';
				break;
			case 12:
				c = 'Q';
				break;
			case 13:
				c = 'K';
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

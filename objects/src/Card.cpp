/*
 * card.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "../inc/Card.h"

Card::Card() {
	this->suit = NONE;
	this->value = 0;
	this->number_val = 0;
}

Card::Card(Suits suit, char value) {
	this->suit = suit;
	this->value = value;
	this->number_val = get_number_val(value);
}

Card::Card(Card* c) {
	this->suit = c->suit;
	this->value = c->value;
	this->number_val = c->number_val;
}

int Card::get_number_val(char c) {
	switch (c) {
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case '0':
			return 10;
		case 'J':
			return 10;
		case 'Q':
			return 10;
		case 'K':
			return 10;
		case 'A':
			return 11;
		default:
			return 0;
	}
}

void Card::print_card() {
	if (this->value == '0')
		std::cout << "10 of " << get_suit(this->suit) << std::endl;
	else
		std::cout << this->value << " of " << get_suit(this->suit) << std::endl;
}

std::string Card::get_suit(Suits s) {
	switch (s) {
		case HEARTS:
			return std::string("Hearts");
		case SPADES:
			return std::string("Spades");
		case CLUBS:
			return std::string("Clubs");
		case DIAMONDS:
			return std::string("Diamonds");
		default:
			return std::string("None");
	}
}

/***********************************
 * Check if two cards are equal    *
 * returns:                        *
 * 0 if none                       *
 * 1 if number matches			   *
 * 2 if both suit and number match *
 ***********************************/
int Card::compare (Card* c) {
	if (this->value != c->value) {
		return 0;
	}
	else {
		if (this->suit == c->suit) {
			return 2;
		}
		else {
			return 1;
		}
	}
}

int Card::get_number_val() {
	return this->number_val;
}

char Card::get_value() {
	return this->value;
}

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
		case TWO:
			return 2;
		case THREE:
			return 3;
		case FOUR:
			return 4;
		case FIVE:
			return 5;
		case SIX:
			return 6;
		case SEVEN:
			return 7;
		case EIGHT:
			return 8;
		case NINE:
			return 9;
		case TEN:
			return 10;
		case JACK:
			return 10;
		case QUEEN:
			return 10;
		case KING:
			return 10;
		case ACE:
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
			return std::string(HEARTS_STRING);
		case SPADES:
			return std::string(SPADES_STRING);
		case CLUBS:
			return std::string(CLUBS_STRING);
		case DIAMONDS:
			return std::string(DIAMONDS_STRING);
		default:
			return std::string(NONE_STRING);
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

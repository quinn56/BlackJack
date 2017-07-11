/*
 * card.h
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include <iostream>
#ifndef OBJECTS_CARD_INC_CARD_H_
#define OBJECTS_CARD_INC_CARD_H_

enum Suits {
	HEARTS,
	SPADES,
	CLUBS,
	DIAMONDS,
	NONE
};

class Card {
	Suits suit;
	char value;
	int number_val;

public:
	Card();
	Card(Suits suit, char value);
	Card(Card* c);
	int get_number_val(char c);
	std::string get_suit(Suits s);
	void print_card();
	int compare(Card* c);
	int get_number_val();
	char get_value();
};



#endif /* OBJECTS_CARD_INC_CARD_H_ */

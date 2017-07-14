/*
 * card.h
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include <iostream>
#ifndef OBJECTS_CARD_INC_CARD_H_
#define OBJECTS_CARD_INC_CARD_H_

#define TWO '2'
#define THREE '3'
#define FOUR '4'
#define FIVE '5'
#define SIX '6'
#define SEVEN '7'
#define EIGHT '8'
#define NINE '9'
#define TEN '0'
#define JACK 'J'
#define QUEEN 'Q'
#define KING 'K'
#define ACE 'A'

static const std::string HEARTS_STRING = "Hearts";
static const std::string SPADES_STRING = "Spades";
static const std::string CLUBS_STRING = "Clubs";
static const std::string DIAMONDS_STRING = "Diamonds";
static const std::string NONE_STRING = "None";

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

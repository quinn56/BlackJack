/*
 * deck.h
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */

#include "Card.h"
#include <vector>

#ifndef OBJECTS_DECK_INC_DECK_H_
#define OBJECTS_DECK_INC_DECK_H_


class Deck {

public:
	Deck();
	void print_deck();
	std::vector<Card*> get_cards();
	void delete_card_at(int i);
private:
	std::vector<Card*> cards;

};



#endif /* OBJECTS_DECK_INC_DECK_H_ */

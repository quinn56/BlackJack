/*
 * dealer.h
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>

#ifndef OBJECTS_DEALER_INC_DEALER_H_
#define OBJECTS_DEALER_INC_DEALER_H_

class Dealer {
	std::vector<Deck*> decks;
	std::vector<Card*> shuffled_deck;
	std::vector<Card*> hand;
	Player* player;
	int ace_count;
public:
	Dealer();
	Player* get_player();
	void deal();
	Card* deal_card();
	void shuffle();
	int get_number_of_cards_left();
	void print_shuffled_deck();
	void print_peek();
	void add_player(Player* p);
	void clear_hand();
	void hit(Player* p);
	void hit();
	void print_hand();
	int get_hand_total();
	std::vector<Card*> get_hand();
};



#endif /* OBJECTS_DEALER_INC_DEALER_H_ */

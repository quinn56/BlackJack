/*
 * player.h
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "Card.h"
#include <vector>

#ifndef OBJECTS_PLAYER_INC_PLAYER_H_
#define OBJECTS_PLAYER_INC_PLAYER_H_

class Player{

int cash;
int bet;
int hands_won;
int hands_played;
int hands_lost;
int hands_pushed;
int ace_count;
int match_dealer;
int biggest_win;
int biggest_match;
std::vector<Card*> hand;

public:
	Player();
	void make_bet(int bet_amount);
	void make_match_bet(int match_amount);
	void add_cash(int amount);
	void add_card_to_hand(Card* c);
	int get_hands_played();
	int get_hands_won();
	int get_hands_lost();
	int get_hands_pushed();
	int get_cash();
	int get_bet();
	int get_match_dealer();
	void print_hand();
	int get_hand_total();
	void clear_hand();
	void inc_hands_played();
	void inc_hands_won();
	void inc_hands_lost();
	void inc_hands_pushed();
	int get_biggest_win();
	void set_biggest_win(int win);
	int get_biggest_match();
	void set_biggest_match(int match);
	std::vector<Card*> get_hand();

};



#endif /* OBJECTS_PLAYER_INC_PLAYER_H_ */

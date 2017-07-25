/*
 * player.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "../inc/Player.h"

Player::Player() {
	this->cash = 0;
	this->bet = 0;
	this->hands_lost = 0;
	this->hands_played = 0;
	this->hands_won = 0;
	this->hands_pushed = 0;
	this->hands_surrendered = 0;
	this->match_dealer = 0;
	this->ace_count = 0;
	this->biggest_win = 0;
	this->biggest_match = 0;
}

void Player::make_bet(int bet_amount) {
	this->bet += bet_amount;
	this->cash -= bet_amount;
}

void Player::make_match_bet(int match_amount) {
	this->match_dealer = match_amount;
	this->cash -= match_amount;
}

void Player::add_cash(int amount) {
	this->cash += amount;
	this->bet = 0;
}

void Player::add_card_to_hand(Card* c) {
	this->hand.push_back(c);
}

int Player::get_hands_played() {
	return this->hands_played;
}

int Player::get_hands_won() {
	return this->hands_won;
}

int Player::get_hands_lost() {
	return this->hands_lost;
}

int Player::get_hands_pushed() {
	return this->hands_pushed;
}

int Player::get_hands_surrendered() {
	return this->hands_surrendered;
}

int Player::get_cash() {
	return this->cash;
}

int Player::get_bet() {
	return this->bet;
}

int Player::get_match_dealer() {
	return this->match_dealer;
}

int Player::get_hand_total() {
	int total = 0;
	for (unsigned int i = 0; i < this->hand.size(); i++) {
		total += this->hand[i]->get_number_val();
		if (this->hand[i]->get_value() == 'A')
			this->ace_count++;
	}

	while (total > 21 && this->ace_count > 0) {
		total -= 10;
		this->ace_count--;
	}
	this->ace_count = 0;
	return total;
}

void Player::print_hand() {
	std::cout <<"\nPlayer has: " << std::endl;
	for (unsigned int i = 0; i < this->hand.size(); i++)
		this->hand[i]->print_card();
	std::cout << "Total: " << this->get_hand_total() << std::endl;
}

void Player::clear_hand() {
	this->hand.clear();
}

void Player::inc_hands_played() {
	this->hands_played++;
}

void Player::inc_hands_won() {
	this->hands_won++;
}

void Player::inc_hands_lost() {
	this->hands_lost++;
}

void Player::inc_hands_pushed() {
	this->hands_pushed++;
}

void Player::inc_hands_surrendered() {
	this->hands_surrendered++;
}

std::vector<Card*> Player::get_hand() {
	return this->hand;
}

void Player::set_biggest_win(int win) {
	this->biggest_win = win;
}

int Player::get_biggest_win() {
	return this->biggest_win;
}

void Player::set_biggest_match(int match) {
	this->biggest_match = match;
}

int Player::get_biggest_match() {
	return this->biggest_match;
}


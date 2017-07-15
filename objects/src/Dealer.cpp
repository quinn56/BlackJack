/*
 * dealer.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: bquinn
 */
#include "../inc/Dealer.h"

Dealer::Dealer() {
	shuffle();
	this->hand.clear();
	this->player = 0;
	this->ace_count = 0;
}

void Dealer::shuffle() {
	this->decks.clear();
	this->shuffled_deck.clear();
	for (int i = 0; i < 8; i++) {
		Deck* d = new Deck();
		this->decks.push_back(d);
	}

	srand (time(NULL));
	int rand_deck = 0;
	int rand_card = 0;

	while (this->shuffled_deck.size() < 250) {
		rand_deck = rand() % 8;
		rand_card = rand() % decks[rand_deck]->get_cards().size();
		Card* card(decks[rand_deck]->get_cards().at(rand_card));
		this->shuffled_deck.push_back(card);
		decks[rand_deck]->delete_card_at(rand_card);
	}
}

void Dealer::print_shuffled_deck() {
	for (unsigned int i = 0; i < this->shuffled_deck.size(); i++)
		this->shuffled_deck[i]->print_card();
}

Player* Dealer::get_player() {
	return this->player;
}

void Dealer::deal() {
	this->hand.push_back(deal_card());
	this->player->add_card_to_hand(deal_card());
	this->hand.push_back(deal_card());
	this->player->add_card_to_hand(deal_card());
}

Card* Dealer::deal_card() {
	if (this->shuffled_deck.size() < 50)
		this->shuffle();
	Card* c = new Card(this->shuffled_deck.back());
	this->shuffled_deck.pop_back();
	return c;
}

void Dealer::print_peek() {
	std::cout <<"\nDealer is showing: " << std::endl;
	this->hand[0]->print_card();
}

void Dealer::add_player(Player* p) {
	this->player = p;
}

void Dealer::clear_hand() {
	this->hand.clear();
}

void Dealer::hit(Player * p) {
	p->add_card_to_hand(deal_card());
}

void Dealer::hit() {
	std::cout <<"\nDealer hits on " << this->get_hand_total() << "..." << std::endl;
	this->hand.push_back(deal_card());
}

int Dealer::get_hand_total() {
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

void Dealer::print_hand() {
	std::cout <<"\nDealer has: " << std::endl;
	for (unsigned int i = 0; i < this->hand.size(); i++)
		this->hand[i]->print_card();
	std::cout << "Total: " << this->get_hand_total() << std::endl;
}

std::vector<Card*> Dealer::get_hand() {
	return this->hand;
}


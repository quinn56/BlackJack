#include <iostream>
#include <iomanip>

#include "../objects/inc/Card.h"
#include "../objects/inc/Dealer.h"
#include "../objects/inc/Deck.h"
#include "../objects/inc/Player.h"

#define MATCH 1
#define SUITED_MATCH 2

void display_welcome() {
	std::cout << "Welcome to Blackjack!"
			"\n/********************/\n"
			"This is an 8-deck game. Dealer stands on soft/hard 17.\n"
			"Double-Down and Surrender allowed.\n"
			"Splitting Not Yet Supported\n"
			"Press enter to begin playing..." << std::endl;
}

void display_starting_amount() {
	std::cout << "How much money are you playing with?: ";
}

void display_bet_message() {
	std::cout << "How much money would you like to bet? (-1 ends game): ";
}

void display_match_dealer_message() {
	std::cout << "How much money would you like to bet on match the dealer?: ";
}

void display_cash(Player* p) {
	std::cout << "Player's current balance $" << p->get_cash() << std::endl;
}

void display_rebet() {
	std::cout << "Bet the same amount this time? (y/n): ";
}

void display_stats(Player* p) {
	std::cout << "\nYou finished with $" << p->get_cash()
			<< "\nHands Played: " << p->get_hands_played()
			<< "\nHands Won: " << p->get_hands_won()
			<< "\nHands Lost: " << p->get_hands_lost()
			<< "\nHands Pushed: " << p->get_hands_pushed()
			<< "\nHands Surrendered: " << p->get_hands_surrendered()
			<< "\nBiggest Win: " << p->get_biggest_win()
			<< "\nBiggest Match: " << p->get_biggest_match()
			<< std::endl;
}

void display_hand_totals(Dealer* d, Player* p) {
	p->print_hand();
	d->print_peek();

}

void display_hand_query() {
	std::cout << "Hit, stand, double down, or surrender? (h/s/d/f): ";
}

void display_bust_message(Player* p) {
	std::cout << "Lose. Player busts with " << p->get_hand_total() << std::endl;
}

void display_bust_message(Dealer* d, int bet) {
	std::cout << "Dealer busts with " << d->get_hand_total() << ". Player wins $" << bet * 2 << std::endl;
}

void display_blackjack_message(int bet) {
	std::cout << "BLACKJACK! Player wins $" << bet * 2.5 << std::endl;
}

void display_win_message(int bet) {
	std::cout << "Player wins $" << bet * 2 << std::endl;
}

void display_push_message() {
	std::cout << "Push. No money lost." << std::endl;
}

void display_lose_message(int bet) {
	std::cout << "Player loses $" << bet << std::endl;
}

void display_surrender_message(int bet) {
	std::cout << "Player surrenders. Loses $" << bet / 2 << std::endl;
}

void display_number_match_message(int match) {
	std::cout << "UN-SUITED MATCH! Pays 4:1. Player wins $" << match * 4 << std::endl;
}

void display_suited_match_message(int match) {
	std::cout << "SUITED MATCH! Pays 14:1. Player wins $" << match * 14 << std::endl;
}

int max(int card1, int card2) {
	return card1 > card2 ? card1 : card2;
}

void check_match_dealer(Player* player, Dealer* dealer) {
	std::cout << "Checking match the dealer..." << std::endl;
	int card1 = player->get_hand().at(0)->compare(dealer->get_hand().at(0));
	int card2 = player->get_hand().at(1)->compare(dealer->get_hand().at(0));

	int match = 0;
	if (card1 == 0 && card2 == 0) {
		std::cout << "No match. Player loses $" << player->get_match_dealer() << std::endl;
		return;
	}
	else {
		match = max(card1, card2);
	}
	if (match == MATCH) {
		display_number_match_message(player->get_match_dealer());
		player->add_cash(player->get_match_dealer() * 4);
		if ((player->get_match_dealer() * 4) > player->get_biggest_match())
			player->set_biggest_match(player->get_match_dealer() * 4);
	}
	else if (match == SUITED_MATCH){
		display_suited_match_message(player->get_match_dealer());
		player->add_cash(player->get_match_dealer() * 14);
		if ((player->get_match_dealer() * 14) > player->get_biggest_match())
					player->set_biggest_match(player->get_match_dealer() * 14);
	}
}

void handle_round(Dealer* dealer, Player* player, int bet, int match) {
	if (bet < 15) {
		if (bet < 0){
			return;
		}
		std::cout << "Table minimum is 15!" << std::endl;
		return;
	}

	player->inc_hands_played();

	player->make_bet(bet);
	player->make_match_bet(match);

	dealer->deal();

	check_match_dealer(player, dealer);

	bool hit = false;
	bool stand = false;
	bool double_down = false;
	bool surrender = false;
	std::string hand_status;

	if (player->get_hand_total() == 21) {
		player->print_hand();
		dealer->print_peek();
		display_blackjack_message(bet);
		player->add_cash(bet * 2.5);
		if ((bet*2.5) > player->get_biggest_win())
			player->set_biggest_win(bet*2.5);
		player->inc_hands_won();
		dealer->clear_hand();
		player->clear_hand();
		return;
	}

	while (player->get_hand_total() < 21 && stand == false) {

		hit = false;
		display_hand_totals(dealer, player);

		display_hand_query();
		std::cin >> hand_status;
		if (hand_status.compare("h") == 0)
			hit = true;
		else if (hand_status.compare("s") == 0)
			stand = true;
		else if (hand_status.compare("d") == 0)
			double_down = true;
		else if (hand_status.compare("f") == 0)
			surrender = true;

		if (surrender) {
			display_surrender_message(bet);
			player->inc_hands_surrendered();
			player->add_cash((bet/2) + 1);
			dealer->clear_hand();
			player->clear_hand();
			return;
		}

		if (hit) {
			dealer->hit(player);
		}

		if (double_down) {
			player->make_bet(player->get_bet());
			dealer->hit(player);
			player->print_hand();
			bet *= 2;
			break;
		}
	}

	if (hit) {
		player->print_hand();
	}

	if (player->get_hand_total() > 21) {
		display_bust_message(player);
		player->inc_hands_lost();
		dealer->clear_hand();
		player->clear_hand();
		return;
	}

	dealer->print_hand();

	while (dealer->get_hand_total() < 21) {

		if (dealer->get_hand_total() < 17) {
			dealer->hit();
			dealer->print_hand();
		}
		else {
			break;
		}
	}

	if (dealer->get_hand_total() > 21) {
		display_bust_message(dealer, bet);
		player->inc_hands_won();
		player->add_cash(bet * 2);
		if ((bet*2) > player->get_biggest_win())
			player->set_biggest_win(bet*2);
	}
	else if (player->get_hand_total() == dealer->get_hand_total()) {
		display_push_message();
		player->inc_hands_pushed();
		player->add_cash(bet);
	}
	else if(player->get_hand_total() > dealer->get_hand_total()) {
		display_win_message(bet);
		player->inc_hands_won();
		if ((bet*2) > player->get_biggest_win())
			player->set_biggest_win(bet*2);
		player->add_cash(bet * 2);
	}
	else {
		display_lose_message(bet);
		player->inc_hands_lost();
	}

	dealer->clear_hand();
	player->clear_hand();
}

int main() {

	Dealer* dealer = new Dealer();
	Player* player = new Player();

	display_welcome();
	std::cin.ignore();

	int cash = 0;
	display_starting_amount();
	std::cin >> cash;

	player->add_cash(cash);
	int bet = 0;
	int match = 0;
	dealer->add_player(player);

	do {
		display_cash(player);
		display_bet_message();
		std::cin >> bet;
		if (bet < 0)
			break;
		display_match_dealer_message();
		std::cin >> match;

		handle_round(dealer, player, bet, match);
	} while(bet > -1);

	display_stats(player);
	return 0;
}

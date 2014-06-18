/*
 * BabylonCounter.h
 *
 *  Created on: Jun 17, 2014
 *      Author: david
 */

#ifndef BABYLONCOUNTER_H_
#define BABYLONCOUNTER_H_

#include <iostream>
#include <set>
#include "GameState.h"

namespace Babylon {

class BabylonCounter {
public:
	static const int MESSAGE_INTERVAL = 100000;
	BabylonCounter();
	void start_counting();


private:
	int games_counted;
	int player_one_wins;
	int player_two_wins;

	void update_count();
	void explore_children(const GameState& p_game, int p_moves_played);
};

} /* namespace Babylon */

#endif /* BABYLONCOUNTER_H_ */

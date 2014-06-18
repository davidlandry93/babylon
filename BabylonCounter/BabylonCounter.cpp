/*
 * BabylonCounter.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: david
 */

#include "BabylonCounter.h"

namespace Babylon {

BabylonCounter::BabylonCounter() :
		games_counted(0), player_one_wins(0), player_two_wins(0)
{
}

void BabylonCounter::start_counting()
{
	GameState root_game = GameState();
	explore_children(root_game, 0);
}

void BabylonCounter::explore_children(const GameState& p_game, int p_moves_played)
{
	std::set<GameState> children = p_game.potential_transitions();
	if(children.empty())
	{
		p_moves_played % 2 == 0 ? player_two_wins++ : player_one_wins++;
		update_count();
	}
	else
	{
		for(std::set<GameState>::iterator i = children.begin(); i != children.end(); i++)
		{
			explore_children(*i, p_moves_played + 1);
		}
	}
}

void BabylonCounter::update_count()
{
	games_counted++;
	if(games_counted % MESSAGE_INTERVAL == 0)
	{
		std::cout << "Games counted: " << games_counted
				<< "(" << player_one_wins << "/" << player_two_wins << ")"
				<< std::endl;
	}
}

} /* namespace Babylon */

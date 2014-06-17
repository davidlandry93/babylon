/*
 * main.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: davidlandry93@gmail.com
 */

#include <iostream>
#include <set>
#include "Stack.h"
#include "GameState.h"

using namespace Babylon;

int main(int argc, const char* argv[])
{
	GameState state = GameState();
	std::cout << state;

	std::set<GameState> moves = state.potential_transitions();

	for(unsigned int i = 0; i< moves.size(); i++)
	{
		std::cout << i << moves[i];
	}

	return 0;
}



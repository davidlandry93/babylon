/*
 * GameState.h
 *
 *  Created on: Jun 17, 2014
 *      Author: dlandry
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "Stack.h"

namespace Babylon {

class GameState {
public:
	static const int N_COLORS = 4;
	static const int N_STONES_PER_COLOR = 3;

	GameState();
	GameState(const GameState& p_state);

	GameState& move(unsigned int p_from, unsigned int p_to);

	friend std::ostream& operator<<(std::ostream& p_stream, const GameState& p_state);
	std::set<GameState> potential_transitions() const;
	std::string to_string() const;
	bool operator<(const GameState& p_rhs) const;
	bool operator==(const GameState& p_rhs) const;

	static bool smaller(const GameState& p_lhs, const GameState& p_rhs);
	static bool equal(const GameState& p_lhs, const GameState& p_rhs);
private:
	std::vector<Stack> m_stacks;

	void reorder();
};



} /* namespace Babylon */


#endif /* GAMESTATE_H_ */

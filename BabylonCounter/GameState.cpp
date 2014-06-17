/*
 * GameState.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: dlandry
 */


#include "GameState.h"

namespace Babylon {

GameState::GameState() {
	m_stacks = std::vector<Stack>();
	for(int i=0; i < N_COLORS; i++)
	{
		for(int j=0; j < N_STONES_PER_COLOR; j++)
		{
			m_stacks.push_back(Stack(i));
		}
	}
}

GameState::GameState(const GameState& p_state) {
	m_stacks = std::vector<Stack>(p_state.m_stacks);
}

GameState& GameState::move(unsigned int p_from, unsigned int p_to)
{
	if(p_from >= m_stacks.size() || p_to >= m_stacks.size())
	{
		throw std::invalid_argument("Invalid indices were specified for the move");
	}

	if(!m_stacks[p_from].can_merge(m_stacks[p_to]))
	{
		throw std::invalid_argument("Illegal move attempted.");
	}

	// Because of this bit of code, it might be better to use a queue
	// instead of a vector for stack.
	m_stacks[p_from] += m_stacks[p_to];
	m_stacks.erase(m_stacks.begin() + p_to);

	reorder();

	return *this;
}

std::vector<GameState> GameState::potential_transitions()
{
	std::set<GameState> potential_transitions;

	for(unsigned int i = 0; i < m_stacks.size(); i++)
	{
		// i+1 because we don't want self stacking.
		for(unsigned int j=i+1; j< m_stacks.size(); j++)
		{
			if(m_stacks[i].can_merge(m_stacks[j]))
			{
				if(std::find(potential_transitions.begin(), potential_transitions.end()))
				{

				}
				potential_transitions.push_back(GameState(*this).move(i,j));
				potential_transitions.push_back(GameState(*this).move(j,i));
			}
		}
	}
	return potential_transitions;
}

std::string GameState::to_string() const
{
	std::ostringstream oss;

	oss << "State: ";
	for(unsigned int i=0; i < m_stacks.size(); i++)
	{
		oss << m_stacks[i];
	}
	oss << std::endl;

	return oss.str();
}

bool GameState::smaller(GameState& p_lhs, GameState& p_rhs)
{

}

std::ostream& operator<<(std::ostream& p_stream, const GameState& p_state)
{
	return p_stream << p_state.to_string();
}

void GameState::reorder()
{
	std::sort(m_stacks.begin(), m_stacks.end(), Babylon::Stack::smaller);
}

} /* namespace Babylon */

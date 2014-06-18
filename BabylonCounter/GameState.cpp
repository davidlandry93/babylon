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

bool GameState::operator<(const GameState& p_rhs) const
{
	return GameState::smaller(*this, p_rhs);
}

std::set<GameState> GameState::potential_transitions() const
{
	std::set<GameState> potential_transitions;

	for(unsigned int i = 0; i < m_stacks.size(); i++)
	{
		// i+1 because we don't want self stacking.
		for(unsigned int j=i+1; j< m_stacks.size(); j++)
		{
			if(m_stacks[i].can_merge(m_stacks[j]))
			{
				potential_transitions.insert(GameState(*this).move(i,j));
				potential_transitions.insert(GameState(*this).move(j,i));
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

bool GameState::smaller(const GameState& p_lhs, const GameState& p_rhs)
{
	std::vector<Stack>::const_iterator left_iter = p_lhs.m_stacks.begin();
	std::vector<Stack>::const_iterator right_iter = p_rhs.m_stacks.begin();

	while(left_iter != p_lhs.m_stacks.end() &&
			right_iter != p_rhs.m_stacks.end())
	{
		if(!Stack::smaller(*left_iter, *right_iter) && !Stack::smaller(*right_iter, *left_iter))
		{
			// The two stacks are equal.
			left_iter++;
			right_iter++;
		} else {
			// The stacks are unequal.
			return Stack::smaller(*left_iter, *right_iter);
		}
	}

	// We reached the end of a word and they are still equal. The longest is the largest.
	return p_lhs.m_stacks.size() < p_rhs.m_stacks.size();
}

bool GameState::operator==(const GameState& p_rhs) const
{
	return GameState::equal(*this, p_rhs);
}

bool GameState::equal(const GameState& p_lhs, const GameState& p_rhs)
{
	if(p_lhs.m_stacks.size() == p_rhs.m_stacks.size())
	{
		for(unsigned int i=0; i < p_lhs.m_stacks.size(); i++)
		{
			if(p_lhs.m_stacks[i] != p_rhs.m_stacks[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
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

/*
 * Stack.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: dlandry
 */

#include "Stack.h"

namespace Babylon {

Stack::Stack(int p_color) : m_color(p_color), m_height(DEFAULT_HEIGHT)
{

}

Stack::Stack(int p_color, int p_height) : m_color(p_color), m_height(p_height)
{

}

int Stack::get_color() const
{
	return m_color;
}

int Stack::get_height() const
{
	return m_height;
}

bool Stack::operator<(const Stack& p_rhs) const
{
	return smaller(*this, p_rhs);
}

bool Stack::operator==(const Stack& p_rhs) const
{
	return m_color == p_rhs.m_color && m_height == p_rhs.m_height;
}

Stack Stack::operator+(const Stack& p_rhs)
{
	if(p_rhs.get_color() != m_color && p_rhs.get_height() != m_height)
	{
		throw std::invalid_argument("Cannot add those two stacks");
	}
	return Stack(m_color, m_height + p_rhs.get_height());
}

Stack& Stack::operator+=(const Stack& p_rhs)
{
	if(p_rhs.get_color() != m_color && p_rhs.get_height() != m_height)
	{
		throw std::invalid_argument("Cannot add those two stacks");
	}

	m_height += p_rhs.get_height();
	return *this;
}

bool Stack::can_merge(const Stack& p_rhs) const
{
	return m_color == p_rhs.get_color() || m_height == p_rhs.get_height();
}

bool Stack::smaller(const Stack& p_lhs, const Stack& p_rhs)
{
	if(p_lhs.get_color() < p_rhs.get_color())
	{
		return true;
	} else if (p_lhs.get_color() == p_rhs.get_color()) {
		return p_lhs.get_height() < p_rhs.get_height();
	} else return false;
}

std::string Stack::to_string() const
{
	std::ostringstream oss;
	oss << '[' << m_color << ',' << m_height << ']';
	return oss.str();
}

std::ostream& operator<<(std::ostream& p_stream, const Stack& p_stack)
{
	return p_stream << p_stack.to_string();
}

} /* namespace Babylon */

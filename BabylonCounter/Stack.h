/*
 * Stack.h
 *
 *  Created on: Jun 17, 2014
 *      Author: dlandry
 */

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <sstream>
#include <stdexcept>

namespace Babylon {

class Stack {
public:
	static const int DEFAULT_HEIGHT = 1;

	Stack(int p_color);
	int get_color() const;
	int get_height() const;

	static bool smaller(const Stack& p_lhs, const Stack& p_rhs);
	bool operator<(const Stack& p_rhs) const;
	bool operator==(const Stack& p_rhs) const;
	bool operator!=(const Stack& p_rhs) const;

	Stack& operator+=(const Stack& p_rhs);
	bool can_merge(const Stack& p_rhs) const;

	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& p_stream, const Stack& p_stack);


private:
	int m_color;
	int m_height;
	Stack(int p_color, int p_height);
};

} /* namespace Babylon */

#endif /* STACK_H_ */

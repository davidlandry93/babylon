/*
 * main.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: davidlandry93@gmail.com
 */

#include <iostream>
#include "Stack.h"

using namespace Babylon;

int main(int argc, const char* argv[])
{
	std::cout << "Hello world!" << std::endl;
	Stack stack = Stack(3);
	Stack stack2 = Stack(1) + stack;
	stack += stack;
	stack += stack;
	std::cout << stack;
	std::cout << stack2;
	std::cout << Stack::smaller(stack, stack);
	std::cout << (stack == stack2);
	std::cout << (stack == stack);
	return 0;
}



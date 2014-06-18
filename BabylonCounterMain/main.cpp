/*
 * main.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: davidlandry93@gmail.com
 */

#include <iostream>
#include <set>
#include "BabylonCounter.h"

using namespace Babylon;

int main(int argc, const char* argv[])
{
	BabylonCounter counter = BabylonCounter();
	counter.start_counting();
	return 0;
}



#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#include <memory>
#include <cassert>
#include <sstream>
#include <array>
#include "Foreach.h"	
#include <functional>

#include <SFML/Graphics.hpp> 
#include <cmath>


template<typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}


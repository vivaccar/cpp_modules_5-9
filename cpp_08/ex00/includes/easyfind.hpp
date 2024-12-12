#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <list>
#include <set>
#include <deque>
#include <stack>

#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

template<typename T>	
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator element = std::find(container.begin(), container.end(), value);
	if (element != container.end())
		return (element);
	throw std::out_of_range("This element does not exist in the container");
}

#endif
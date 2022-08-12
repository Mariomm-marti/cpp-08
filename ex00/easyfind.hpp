#pragma once
#ifndef CPP08_EX00_EASYFIND_H_
# define CPP08_EX00_EASYFIND_H_

# include <iostream>
# include <algorithm>
# include <string>

template <typename T>
void	easyfind(T const &param, int const num)
{
	if (param.end() == std::find(param.begin(), param.end(), num))
		throw std::exception();
}

#endif

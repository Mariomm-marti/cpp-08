#pragma once
#ifndef CPP08_EX00_EASYFIND_H_
# define CPP08_EX00_EASYFIND_H_

# include <iostream>
# include <string>

template <typename T>
void	easyfind(T const &param, int const num)
{
	typename T::const_iterator	it;
	
	it = param.begin();
	while (it != param.end())
	{
		if (*it == num)
		{
			std::cout << "easyfind: found " << num << std::endl;
			return ;
		}
		it++;
	}
	throw std::exception();
}

#endif

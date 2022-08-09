#include <list>
#include <vector>
#include "easyfind.hpp"

int		main(void)
{
	{
		std::list<int>	numbers;

		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(4);
		numbers.push_back(5);
		::easyfind(numbers, 1);
		::easyfind(numbers, 4);
		::easyfind(numbers, 3);
		try
		{
			::easyfind(numbers, 7);
		}
		catch (std::exception const &e)
		{
			std::cout << "Number not found in list<int>" << std::endl;
		}
	}
	{
		std::vector<int>	numbers;

		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(4);
		numbers.push_back(5);
		::easyfind(numbers, 1);
		::easyfind(numbers, 4);
		::easyfind(numbers, 3);
		try
		{
			::easyfind(numbers, 7);
		}
		catch (std::exception const &e)
		{
			std::cout << "Number not found in vector<int>" << std::endl;
		}
	}
}

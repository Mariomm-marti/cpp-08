#include <vector>
#include <stdexcept>
#include <iostream>
#include "span.hpp"

int	main(void)
{
	{
		// Test by subject
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// 0-length span
		try
		{
			Span	sp = Span(0);
		}
		catch (std::invalid_argument const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// 1-length span filled and try to add more numbers
		try
		{
			Span	sp = Span(1);

			sp.addNumber(28);
			sp.addNumber(32);
		}
		catch (std::length_error const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// 1-length span filled and shortestSpan called
		try
		{
			Span	sp = Span(1);

			sp.addNumber(28);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::underflow_error const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// 1-length span filled and longestSpan called
		try
		{
			Span	sp = Span(1);

			sp.addNumber(28);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::underflow_error const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// 2-length span filled, shortestSpan and longestSpan called
		Span	sp = Span(2);

		sp.addNumber(28);
		sp.addNumber(0);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// 2-length span filled, checking behaviour of negative span values
		Span	sp = Span(2);

		sp.addNumber(-14);
		sp.addNumber(-19);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// 3-length span filled, shortestSpan and longestSpan called
		Span	sp = Span(3);

		sp.addNumber(28);
		sp.addNumber(11);
		sp.addNumber(0);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// 2-length span not totally filled, shortestSpan and longestSpan called
		Span	sp = Span(3);

		sp.addNumber(14);
		sp.addNumber(29);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// 100000-length span totally filled, shortestSpan and longestSpan called
		Span				sp = Span(100000);
		std::vector<int>	originalVector = std::vector<int>(100000, 29);

		sp.addNumber(originalVector.begin(), originalVector.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.size() << std::endl;
		std::cout << sp.length() << std::endl;
	}
}

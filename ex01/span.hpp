#pragma once
#ifndef CPP08_EX01_SPAN_H_
# define CPP08_EX01_SPAN_H_

class Span
{
private:
	int				*_numbers;
	unsigned int	_size;
	unsigned int	_usedSpace;

	Span(void);

public:
	Span(unsigned int const size);
	Span(Span const &rhs);
	~Span(void);

	Span			&operator=(Span const &rhs);
	int				operator[](unsigned int const index) const;
	unsigned int	size(void) const;
	unsigned int	length(void) const;

	void			addNumber(int const number);
	void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned long	shortestSpan(void) const;
	unsigned long	longestSpan(void) const;
};

#endif

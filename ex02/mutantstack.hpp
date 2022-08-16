#pragma once
# ifndef CPP08_EX02_MUTANTSTACK_H_

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
  typedef typename std::stack<T>::container_type::iterator  iterator;

  iterator  begin(void)
  {
    return this->c.begin();
  }
  iterator  end(void)
  {
    return this->c.end();
  }
};

#endif

#include <iostream>
#include <stack>
#include <algorithm>

template < typename T, typename container = std::deque<T> >

class MutantStack : public std::stack< T, container >
{
public:
    typedef typename std::stack<T, container>::container_type::iterator iterator;
    MutantStack() : std::stack<T, container>(){}
    MutantStack(container input) : std::stack<T, container>(input){}
    virtual ~MutantStack(){};
    MutantStack(const MutantStack& other) : std::stack<T, container>(other){
        std::cout << " Copy constructor is called." << std::endl;
    }
    MutantStack& operator=(const MutantStack& other){
        std::cout << " Copy Assignment operator is called." << std::endl;
        if (this != &other)
            return (*this);
        return (*this);
    }
    iterator begin(){
        return (this->c.begin());
    }
    iterator end(){
        return (this->c.end());
    }
};
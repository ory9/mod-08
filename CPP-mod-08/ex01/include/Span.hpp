#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _N;
    std::vector<unsigned int>_array;
    unsigned int _size;
public:
    Span();
    Span(unsigned int n);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
    bool operator!=(const Span& other);
    void addNumber(unsigned int N);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void addVector(std::vector<unsigned int>at);
    class FullArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NoSpanException : public std::exception{
    public:
        virtual const char *what() const throw();
    };
};
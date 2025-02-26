#include "../include/Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _N(n), _size(0) {
   _array.reserve(n);
}
Span::~Span() {}

Span::Span(const Span& other)
{
    this->_N = other._N;
    this->_array = other._array;
    this->_size = other._size;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        this->_N = other._N;
        this->_size = other._size;
    }
    return *this;
}

void Span::addNumber(unsigned int N){
    
    try{
        if (_size >= _N){
            throw FullArrayException();
        }
        _array.push_back(N);
        _size++;
    }
    catch(const std::exception &e){
        std::cout << "Error: " << e.what() <<  std::endl;
    }
}

unsigned int Span::longestSpan(){
    unsigned int min = _array[0];
    unsigned int max = _array[0];
    if (_size > _N ||  _array.size() > _N || _array.size() <= 1)
        throw FullArrayException();
    for (unsigned int i = 0; i < _array.size(); i++)
    {
        if (_array[i] < min)
            min = _array[i];
        if (_array[i] > max)
            max = _array[i]; 
    }
    return (max - min);
}

unsigned int Span::shortestSpan()
{
    if (_size <= 1)
        throw NoSpanException();
    std::vector<unsigned int> tmp(_array);
    std::sort(tmp.begin(), tmp.end());
    unsigned int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < _size - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < min)
            min = tmp[i + 1] - tmp[i];
    }
    return (min);
}

void Span::addVector(std::vector<unsigned int>at){
    if (at.size() + at.size() > _N)
        throw FullArrayException();
    _array.insert(_array.end(), at.begin(), at.end());
    _size += at.size();
}

const char * Span::FullArrayException::what() const throw(){
    return ("Number of elements exceeded 'N' - Limit");
}

const char * Span::NoSpanException::what() const throw(){
    return ("No Span elements found!");
}


#include <iostream>
#include <vector>

template <typename T>
class Data
{
public:
    Data() {}
    ~Data() {}
    std::vector<T> data;
    
    Data(const Data& other)
    {
        data = other.data;
    }

    Data& operator=(const Data& other)
    {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    bool operator!=(const Data& other) const
    {
        return data != other.data;
    }

    void easyfinder(Data<T>& data, T num)
    {
        // Explicit iterator type
        typename std::vector<T>::iterator it;
        
        bool found = false;
        for (it = data.data.begin(); it != data.data.end(); ++it) {
            if (*it == num) 
            {
                std::cout << *it << std::endl;
                found = true;  // Mark that we found a match
                break;
            }
        }
    
        if (!found) {
            std::cout << "Value not found!" << std::endl;
        }
    }
};
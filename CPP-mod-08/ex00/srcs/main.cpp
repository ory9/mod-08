#include "../include/ easyfind.hpp"

int main() {
    Data<int> d2;
    int sum = 0;

    // Add some data to d2 for testing
    for (int i = 0; i < 20; i++)
    {
        d2.data.push_back(sum += (i * 10));
    }
    
    try{
        d2.easyfinder(d2, 10);
        d2.easyfinder(d2, 110);
        d2.easyfinder(d2, 30);
        d2.easyfinder(d2, 50);
        d2.easyfinder(d2, 1900);
    }
    catch(const std::exception &e){
        std::cout << "Error: " << e.what() <<  std::endl;
    }

    return 0;
}
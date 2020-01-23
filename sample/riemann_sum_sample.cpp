#include <iostream>
#include "../src/riemann.h"
#include "../src/function.h"
#include "../lib/fparser/fparser.hh"

int main (int args, char * argl [])
{
    std::cout << "Riemann integral example" << std::endl;
    
    spivak::riemann riemann;

    spivak::function f("x^4 - 3*x^2 + 1");

    std::cout << riemann.left_sum(f, -1, 1.9, 29) << std::endl;
    return 0;   
}
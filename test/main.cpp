#include <iostream>
#include <MyFancySquareRoot.hpp>

int main()
{
    double arg = 3.44;
    MyFancySquareRoot sqroot(arg);
    std::cout << "Result is: " << sqroot.getSquareRoot() << std::endl;
    return (0);
}

#ifndef MY_FANCY_SQUAREROOT_HPP_
#define MY_FANCY_SQUAREROOT_HPP_

#include <cmath>
#include <limits>

class MyFancySquareRoot
{
public:
    MyFancySquareRoot(double arg) : inputNumber(arg) {}
    double getSquareRoot() const;

private:
    double inputNumber;

};

#endif

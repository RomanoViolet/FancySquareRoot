#include <MyFancySquareRoot.hpp>

double MyFancySquareRoot::getSquareRoot() const
{
    if (this->inputNumber < 0)
    {
        return (std::numeric_limits<double>::quiet_NaN());
    }
    else
    {
        return (sqrt(this->inputNumber));
    }
}

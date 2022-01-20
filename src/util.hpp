#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>

namespace Util
{
    template<typename T>
    static void Print(T toPrint)
    {
        std::cout << toPrint << std::endl;
    };
}

#endif
#include <iostream>

namespace Util
{
    template<typename T>
    static void Print(T toPrint)
    {
        std::cout << toPrint << std::endl;
    };
}

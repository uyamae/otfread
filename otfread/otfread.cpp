#include "otfread.h"
#include <iostream>

namespace otfread
{
    void read(void * data, size_t size)
    {
        char * p = static_cast<char *>(data);
        while (size--)
        {
            std::cout << static_cast<int>(*p++) << ",";
        }
        std::cout << std::endl;
    }
}


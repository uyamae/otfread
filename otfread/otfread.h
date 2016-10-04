#if !defined(OTFREAD_OTFREAD_H)
#define OTFREAD_OTFREAD_H

#include <cstddef>

namespace otfread
{
    bool readfile(const char * name);
    bool read(void * data, size_t size);
}

#endif // OTFREAD_OTFREAD_H

#ifndef CHECKSTRING_HPP
#define CHECKSTRING_HPP

#include <iostream>

namespace belobrov
{
    char* inputString(std::istream& input);
    char* resizeBuffer(const char* oldBuffer, size_t newSize);
}

#endif

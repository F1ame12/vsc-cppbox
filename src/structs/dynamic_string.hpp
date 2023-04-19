#ifndef __DYNAMIC_STRING_HPP__
#define __DYNAMIC_STRING_HPP__

#include "../common/std_basic.h"

class DynamicString
{
private:
    std::unique_ptr<char[]> innerCharPtr;
    int charSize;

public:
    DynamicString(const int size = 16)
    {
        innerCharPtr = std::make_unique<char[]>(size);
        charSize = 0;
    }

    void Resize(const int size)
    {
        auto newPtr = std::make_unique<char[]>(size);
        std::strcpy(newPtr.get(), innerCharPtr.get());
        innerCharPtr.reset(newPtr.release());
    }
};

#endif
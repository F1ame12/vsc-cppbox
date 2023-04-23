#ifndef __DYNAMIC_STRING_HPP__
#define __DYNAMIC_STRING_HPP__

#include "../common/std_basic.h"

namespace myds
{
    class DynamicString
    {
    protected:
        std::unique_ptr<char[]> innerCharPtr;
        int charSize;
        int capicity;

    public:
        DynamicString(const int size = 16)
        {
            innerCharPtr = std::make_unique<char[]>(size);
            charSize = 0;
            capicity = size;
        }

        void Resize(const int size)
        {
            auto newPtr = std::make_unique<char[]>(size + 1);
            std::strncpy(newPtr.get(), innerCharPtr.get(), size);
            newPtr[size] = '\0';
            innerCharPtr.reset(newPtr.release());
            this->capicity = size;
            if (this->charSize > size)
            {
                this->charSize = size;
            }
        }

        void add(const std::string &src)
        {
            if (src.size() >= this->capicity)
            {
                int newSize = src.size() * 2;
                this->Resize(newSize);
            }
            std::strcpy(innerCharPtr.get() + this->charSize, src.c_str());
            this->charSize += src.size();
            innerCharPtr[this->charSize] = '\0';
        }

        std::string toString() const
        {
            return std::string(innerCharPtr.get());
        }
    };
}

std::ostream &operator<<(std::ostream &os, const myds::DynamicString &ds)
{
    os << ds.toString();
    return os;
}

#endif
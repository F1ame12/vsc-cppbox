#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include "./std_basic.h"

namespace Util
{
    const std::string randStr(const int maxLen)
    {
        static const std::string basicStr {"abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTVWXYZ0123456789"};
        static std::random_device rd;
        static std::mt19937_64 mt(rd());

        if (maxLen <= 0) return "";
        
        std::uniform_int_distribution ud(0, static_cast<int>(basicStr.length() - 1));

        char buffer[maxLen] {};
        for (int i = 0; i < maxLen; i++)
        {
            const int randPos = ud(mt);
            buffer[i] = basicStr.at(randPos);
        }

        return std::string(buffer);
    }
}


#endif
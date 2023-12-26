#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include "./std_basic.h"

namespace Util
{
    const std::string randStr(const int maxLen)
    {
        static const std::string basicStr{"abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTVWXYZ0123456789"};
        static std::random_device rd;
        static std::default_random_engine engine(rd());

        if (maxLen <= 0)
            return "";

        std::uniform_int_distribution ud(0, static_cast<int>(basicStr.length() - 1));

        char buffer[maxLen]{};
        for (int i = 0; i < maxLen; i++)
        {
            const int randPos = ud(engine);
            buffer[i] = basicStr.at(randPos);
        }

        return std::string(buffer);
    }

    /**
     * 判断主机字节序是否是小端
    */
    bool IsLittleEndian()
    {
        const int n = 1;
        const char *p = (char *)(&n);
        if (*p == 1)
            return true;
        return false;
    }
}

#endif
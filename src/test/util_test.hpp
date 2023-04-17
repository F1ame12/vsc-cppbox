#ifndef __UTIL_TEST_HPP__
#define __UTIL_TEST_HPP__

#include "../common/std_basic.h"
#include "../common/util.hpp"

namespace UtilTest
{
    void TestGenStr()
    {
        using std::string;

        string test = Util::randStr(16);
        string test2 = Util::randStr(32);
        string test3 = Util::randStr(1024);
        string test4 = Util::randStr(0);

        using std::cout, std::endl;
        cout << test << endl;
        cout << test2 << endl;
        cout << test3 << endl;
        cout << test4 << endl;
    }

    void TestMultiGenStr()
    {
        std::unordered_set<std::string> strSet;
        const int max = std::pow(10, 4);

        for (int i = 0; i < max; i++)
        {
            srand(std::time(nullptr));
            const int randLen = std::floor((rand()) * 31) + 1;
            const std::string str = Util::randStr(randLen);
            auto it = strSet.find(str);
            if (it != strSet.end())
            {
                std::cout << "TEST FAILED" << std::endl;
                return;
            }
            strSet.insert(str);
        }

        std::filesystem::path logPath("./logs/gen_strs.log");
        

        std::ofstream stream("");
        if (stream.is_open())
        {
            for (const auto &str : strSet)
            {
                stream << str << std::endl;
            }
        }
    }

}

#endif
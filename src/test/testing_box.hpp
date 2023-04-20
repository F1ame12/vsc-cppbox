#ifndef __TEST_BOX_HPP__
#define __TEST_BOX_HPP__

#include "../common/std_basic.h"

namespace TestBox
{
    void testStream()
    {
        using namespace std;

        istringstream s("1,2,3,4,5");

        char buffer[1024] {};
        while (s.getline(buffer, 1024, ','))
        {
            cout << buffer << endl;
        }
    }

    void TestStringModify()
    {
        std::string buffer;
        buffer.reserve(1024);

        assert(buffer.data() == &buffer[0]);
        buffer.data()[0] = '1';
        buffer.data()[1] = '\0';
        std::cout << buffer << " " << buffer.data();
    }
}

#endif
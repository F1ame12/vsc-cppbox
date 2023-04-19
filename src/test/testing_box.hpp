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
}

#endif
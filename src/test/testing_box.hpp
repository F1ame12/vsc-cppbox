#ifndef __TEST_BOX_HPP__
#define __TEST_BOX_HPP__

#include "../common/std_basic.h"

namespace TestBox
{
    void testStream()
    {
        using namespace std;

        char buffer[1024];
        while (cin.getline(buffer, 1024, ','))
        {
            cout << buffer << endl;
        }
    }
}

#endif
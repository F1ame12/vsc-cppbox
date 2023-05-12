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
        using namespace std;
        std::string buffer {"testcontent"};
        buffer.reserve(1024);

        cout << buffer.data() << endl;

        char* ptr = buffer.data();

        ptr[0] = '2';
        ptr[1] = '3';

        while(cin.getline(buffer.data(), buffer.capacity())) {};

        cout << buffer;
    }


    void TestMemAlign()
    {
        using namespace std;

        cout << sizeof(short) << " " << sizeof(int) << " "
            << sizeof(long) << " " << sizeof(long long) << " "
            << sizeof(int*) << " "
            << endl;
    }
}

#endif
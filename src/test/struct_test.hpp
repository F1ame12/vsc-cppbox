#ifndef __STRUCT_TEST_HPP__
#define __STRUCT_TEST_HPP__

#include "../common/std_basic.h"
#include "../structs/mylist.hpp"

namespace StructTest
{
    void LinkListTest()
    {
        myds::List<int> list;
        for (int i = 0; i < 6; i++)
        {
            list.Append(i);
        }
        
        assert(list.ToString() == "[0,1,2,3,4,5]");

        list.Remove(3);
        assert(list.ToString() == "[0,1,2,4,5]");

        list.Clear();
        assert(list.ToString() == "[]");
    }

    void TestAll()
    {
        LinkListTest();

        using std::cout,std::endl;
        cout << "Struct Test Finished" << endl;
    }


    
}

#endif
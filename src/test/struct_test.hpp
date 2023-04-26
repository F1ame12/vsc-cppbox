#ifndef __STRUCT_TEST_HPP__
#define __STRUCT_TEST_HPP__

#include "../common/std_basic.h"
#include "../structs/mylist.hpp"
#include "../structs/dynamic_string.hpp"
#include "../structs/heap.hpp"

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

    void DynamicStringTest()
    {
        myds::DynamicString ds {6};
        ds.add("123456");
        std::cout << ds << std::endl;
    }

    void HeapTest()
    {
        using std::cout, std::endl;
        myds::Heap<int> heap {5,4,3,2,1};
        // 5 1 3 2 4
        // 1 5 3 2 4
        // 1 2 3 5 4
        cout << heap.ToString() << endl;
    }

    void TestAll()
    {
        //LinkListTest();
        DynamicStringTest();

        using std::cout, std::endl;
        cout << "Struct Test Finished" << endl;
    }

}

#endif
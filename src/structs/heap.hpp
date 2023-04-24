#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <vector>
#include <memory>

namespace myds
{
    template <class T>
    class Heap
    {
    private:
        std::unique_ptr<T[]> elements;

    public:
        Heap()
        {
            elements = std::make_unique<T[]>(10);
        }

    private:
        void MakeHeap()
        {

        }
    };
}

#endif
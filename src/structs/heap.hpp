#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <vector>
#include <memory>
#include <initializer_list>
#include <functional>
#include <string>
#include <iostream>

namespace myds
{
    template <class T, class Compare = std::less<T>>
    class Heap
    {

    protected:
        std::unique_ptr<T[]> elements;
        std::size_t elemSize;
        std::size_t capacity;

        Compare compare;

    public:
        Heap(std::initializer_list<T> elems)
        {
            capacity = elems.size();
            elemSize = elems.size();
            elements = std::make_unique<T[]>(elems.size());

            int count = 0;
            for (const T& e : elems)
            {
                elements[count++] = e;
            }

            this->MakeHeap();
        }

        void Resize(const size_t size)
        {
            std::unique_ptr<T[]> newElems = std::make_unique<T[]>(size);

            this->capacity = size;
            if (this->elemSize > size) 
                this->elemSize = size;

            memcpy_s(newElems.get(), sizeof(T) * size, elements.get(), sizeof(T) * this->elemSize);
            
            this->elements.reset(newElems.release());
        }

        std::string ToString() const
        {
            std::ostringstream stream;
            stream << "[";
            for (int i = 0; i < this->elemSize; i++)
            {
                stream << this->elements[i];
                if (i + 1 != this->elemSize)
                {
                    stream << ",";
                }
            }
            stream << "]";
            return stream.str();
        }

    protected:
        int Parent(const int index)
        {
            return (index - 1) >> 1;
        }
        int LeftChild(const int index)
        {
            return (index << 1) + 1;
        }
        int RightChild(const int index)
        {
            return (index << 1) + 2;
        }

        void MakeHeap()
        {
            
        }

        void ShiftUp(const int index)
        {
            int parent = this->Parent(index);
            int i = index;
            while (i > 0 && this->compare(this->elements[i], this->elements[parent]))
            {
                std::swap(this->elements[i], this->elements[parent]);
                i = parent;
                parent = this->Parent(i);
            }
        }

        void ShiftDown(const int index)
        {
            int parent = index;
            do
            {
                int change = -1;

                int left = this->LeftChild(parent);
                if (left < this->elemSize && this->compare(this->elements[left], this->elements[parent]))
                {
                    change = left;   
                }

                int right = this->RightChild(parent);
                if (right < this->elements && this->compare(this->elements[right], this->elements[parent]))
                {
                    change = right;
                }

                if (change != -1)
                {
                    std::swap(this->elements[parent], this->elements[change]);
                }
                parent = change;

            } while (parent != -1);
        }
    };
}

#endif
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

        const int Insert(const T& value)
        {
            if (this->elemSize >= this->capacity)
            {
                this->Resize(this->capacity * 2);
            }
            this->elements[this->elemSize] = value;
            return this->ShiftUp(this->elemSize++);
        }

        T Pop()
        {
            T tmp = this->elements[0];
            this->elements[0] = this->elements[this->elemSize - 1];
            this->elemSize--;
            this->ShiftDown(0);
            return tmp;
        }

    protected:
        int Parent(const int index)
        {
            return (index - 1) / 2;
        }
        int LeftChild(const int index)
        {
            return (index * 2) + 1;
        }
        int RightChild(const int index)
        {
            return (index * 2) + 2;
        }

        void MakeHeap()
        {
            for (int index = (this->elemSize - 1) / 2; index >= 0; index--)
            {
                this->ShiftDown(index);
            }
        }

        const int ShiftUp(const int index)
        {
            int parent = this->Parent(index);
            int i = index;
            while (i > 0 && this->compare(this->elements[i], this->elements[parent]))
            {
                std::swap(this->elements[i], this->elements[parent]);
                i = parent;
                parent = this->Parent(i);
            }
            return i;
        }

        /**
         * 非递归式元素下沉操作
         * 从传入结点的左右子结点中选出最优先于传入结点的结点并交换位置
         * 持续上述操作直至抵达叶子结点
        */
        void ShiftDown(const int index)
        {
            int parent = index;
            int last = parent;
            do
            {
                int larger = parent;
                int left = this->LeftChild(parent);
                if (left < this->elemSize && this->compare(this->elements[left], this->elements[larger]))
                {
                    larger = left;
                }

                int right = this->RightChild(parent);
                if (right < this->elemSize && this->compare(this->elements[right], this->elements[larger]))
                {
                    larger = right;
                }

                if (larger != parent)
                {
                    std::swap(this->elements[parent], this->elements[larger]);
                }
                last = parent;
                parent = larger;

            } while (parent != last);
        }
    };
}

#endif
#ifndef __MYLIST_HPP__
#define __MYLIST_HPP__

#include <string>
#include <sstream>

namespace myds
{
    template<class T>
    class IList
    {
    public:
        virtual void Append(T value) = 0;
        virtual void Remove(T value) = 0;
        virtual T Get(const int index) = 0;
        virtual const int Size() = 0;
        virtual void Clear() = 0;
        virtual std::string ToString() = 0;
        virtual void Set(T value, T index) = 0;

    };

    template<class T>
    class List : public IList<T>
    {
    private:
        struct Node
        {
            T value;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;
        unsigned int size;

    public:
        List()
        {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~List()
        {
            this->Clear();
        }

        const int Size() override
        {
            return this->size;
        }

        void Clear() override
        {
            Node* cursor = this->head;
            while (cursor)
            {
                Node* tmp = cursor;
                cursor = cursor->next;
                delete tmp;
            }
            this->head = nullptr;
            this->tail = nullptr;
            size = 0;
        }

        T Get(const int index) override
        {
            if (index < 0) return T();
            if (index >= this->size) return T();

            Node* cursor = this->head;
            for (int i = 0; i < index; i++)
            {
                cursor = cursor->next;
            }
            return cursor->value;
        }

        void Set(T value, T index) override
        {
            if (index < 0 || index >= this->size) return;

            Node* cursor = this->head;
            while (index-- > 0)
            {
                cursor = cursor->next;
            }
            cursor->value = value;
        }

        void Append(T value) override
        {
            if (this->head == nullptr)
            {
                Node* newNode = new Node();
                newNode->value = value;
                this->head = newNode;
                this->tail = newNode;
                this->size = 1;
            }
            else
            {
                Node* newNode = new Node();
                newNode->value = value;
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                this->size++;
            }
        }

        void Remove(T value) override
        {
            Node* target = this->head;
            while (target)
            {
                if (target->value == value) break;
                target = target->next;
            }
            if (target->next) target->prev->next = target->next;
            if (target->prev) target->next->prev = target->prev;
            delete target;
            this->size--;
        }

        std::string ToString() override
        {
            std::ostringstream stream;
            stream << "[";
            Node* cursor = this->head;
            for (int i = 0; i < this->size; i++)
            {
                stream << cursor->value;
                cursor = cursor->next;
                if (i + 1 != this->size)
                {
                    stream << ",";
                }
            }
            stream << "]";

            return stream.str();
        }

        
    };

}


#endif






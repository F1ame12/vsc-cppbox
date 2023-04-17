#ifndef __MYLIST_HPP__
#define __MYLIST_HPP__

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
        virtual void Print() = 0;
        virtual void Sort() = 0;
        virtual void Reverse() = 0;
        virtual void Insert(T value, T index) = 0;
        virtual void RemoveAt(T index) = 0;
        virtual void Set(T value, T index) = 0;
        virtual void AddRange(T* values, T count) = 0;
        virtual void RemoveRange(T* values, T count) = 0;
        virtual void InsertRange(T* values, T count, T index) = 0;
        virtual void RemoveRangeAt(T* values, T count, T index) = 0;
        virtual void SetRange(T* values, T count, T index) = 0;
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

        const int Size() const override
        {
            return this->size;
        }

        void Clear() override
        {
            Node* cursor = this->head;
            while (cursor->next)
            {
                Node* tmp = cursor;
                cursor = cursor->next;
                delete tmp;
            }
            this->head = nullptr;
            this->tail = nullptr;
            size = 0;
        }

        void Append(T value) override
        {
            if (this->head == nullptr)
            {
                Node* newNode = new Node();
                newNode->value = T;
                this->head = newNode;
                this->tail = newNode;
                this->size = 1;
            }
            else
            {
                Node* newNode = new Node();
                newNode->value = T;
                newNode->next = this->tail;
                newNode->prev = this->tail->prev;
                this->tail->prev = newNode;
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
        }

        
    };

}


#endif






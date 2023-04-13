#ifndef __MYLIST_HPP__
#define __MYLIST_HPP__

namespace myds
{
    class IList 
    {
    public:
        virtual void Add(int value) = 0;
        virtual void Remove(int value) = 0;
        virtual int Get(int index) = 0;
        virtual int Size() = 0;
        virtual void Clear() = 0;
    };

    class LinkList : public IList
    {
    private:
        struct Node
        {
            int value = 0;
            Node* next = nullptr;
        };

        Node* head;
        int size;
    public:
        LinkList();
        ~LinkList();

        void Add(int value);
        void Remove(int value);
        int Get(int index);
        int Size();
        void Clear();
    };
}


#endif






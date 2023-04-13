#ifndef __MYLIST_H__
#define __MYLIST_H__

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






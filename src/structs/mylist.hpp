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
        LinkList()
        {
            head = nullptr;
            size = 0;
        }

        ~LinkList()
        {
            this->Clear();
        }

        LinkList(const LinkList& other)
        {
            head = nullptr;
            size = 0;
            Node* p = other.head;
            while (p != nullptr)
            {
                this->Add(p->value);
                p = p->next;
            }
        }

        void Add(int value) override 
        {
            Node* p = new Node();
            p->value = value;
            p->next = head;
            head = p;
            size++;
        }
        void Remove(int value) override
        {
            Node* p = head;
            Node* q = nullptr;
            while (p != nullptr)
            {
                if (p->value == value)
                {
                    if (q == nullptr)
                    {
                        head = p->next;
                    }
                    else
                    {
                        q->next = p->next;
                    }
                    delete p;
                    size--;
                    break;
                }
                q = p;
                p = p->next;
            }
        }
        int Get(int index);
        int Size();
        void Clear();
    };
}


#endif






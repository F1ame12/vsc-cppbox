#ifndef __SKIP_LIST_HPP__
#define __SKIP_LIST_HPP__

#include <vector>

template<class T>
struct SkipNode {
    T Value;
    SkipNode* Next = nullptr;
    SkipNode* Prev = nullptr;
    unsigned int Span = 0;
};

template<class T>
class SkipList {

private:
    static const unsigned int DEFAULT_LAYER_NUM = 8;
    std::vector<SkipNode<T>> Heads;

public:
    SkipList() {
        
    }

};


#endif
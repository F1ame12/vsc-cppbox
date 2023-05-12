#ifndef __TEXT_FILTER_HPP__
#define __TEXT_FILTER_HPP__

#include <unordered_map>
#include <vector>
#include <string>

class TextFilter
{
private:
    struct TextKey
    {
        wchar_t nextKey = 0;
        bool isEnd = false;

        TextKey(wchar_t key, bool isEnding) : nextKey(key), isEnd(isEnding)
        {
        }

        TextKey() = default;
    };

    std::unordered_map<wchar_t, TextKey> filterMap;

public:
    TextFilter(const std::vector<std::wstring> &filterTexts)
    {
        this->buildFilterMap(filterTexts);
    }

    TextFilter(const TextFilter &filter)
    {
        this->filterMap = filter.filterMap;
    }

    TextFilter &operator=(const TextFilter &filter)
    {
        this->filterMap = filter.filterMap;
        return *this;
    }

    bool check(const std::wstring &src, int &outStartPos, int &outEndPos)
    {
        // ! problem
    }

private:
    // 构建过滤字符DFA树
    void buildFilterMap(const std::vector<std::wstring> &texts)
    {
        for (const auto &str : texts)
        {
            wchar_t last = '';
            for (const auto it = str.cbegin(); it != str.cend(); it++)
            {
                TextKey &textKey = this->filterMap[*it];
                if (last != '')
                {
                    TextKey &lastKey = this->filterMap[last];
                    lastKey.nextKey = *it;
                    lastKey.isEnd = false;
                }
                if (it + 1 == str.cend())
                {
                    textKey.isEnd = true;
                }
                last = *it;
            }
        }
    }
}

#endif
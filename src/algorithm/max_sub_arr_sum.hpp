#include <vector>
#include <limits>
#include <map>

using std::vector;

/**
 * LeetCode 53. 最大子序和
*/


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        return 0;
    }
};


/**
 * 动态规划方法
*/
class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxNum = std::numeric_limits<int>::min();

        int perSum = 0;
        for (const int &num : nums)
        {
            perSum = std::max(perSum + num, num);
            maxNum = std::max(maxNum, perSum);
        }

        return maxNum;
    }
};
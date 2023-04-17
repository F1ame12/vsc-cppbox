#include "../common/std_basic.h"

/**
 * LeetCode 53. 最大子序和
*/

/**
 * 分治法
*/
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {

        return 0;
    }
};


/**
 * 动态规划方法
 * 假设 f(i) 为以第 i 个元素结尾的最大子序和
 * 则有以下递推公式：
 * f(i) = max(f(i-1), nums[i])
*/
class Solution1
{
public:
    int maxSubArray(std::vector<int> &nums)
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
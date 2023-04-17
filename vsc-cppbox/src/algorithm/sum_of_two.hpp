#include "../common/std_basic.h"

/**
 * leetcode 1 两数之和
*/

/**
 * target = A + B
 * A 和 B 一定在数组内
 * 将数组过一遍记录下遍历过的数字对应数组下标则一定能在 O(n) 时间内找到
*/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = numMap.find(target - nums[i]);
            if (it != numMap.end())
            {
                return {i, it->second};
            }
            else
            {
                numMap.insert({nums[i], i});
            }
        }
        return {};
    }
};

void test()
{
    std::vector<int> nums = {2,4,11,3};
    int target = 6;

    Solution s;
    auto vec = s.twoSum(nums, target);
    std::cout << "[" << vec[0] << "," << vec[1] << "]" << std::endl;
}
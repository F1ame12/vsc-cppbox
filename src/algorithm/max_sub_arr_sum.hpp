#include <vector>
#include <limits>
#include <map>

using std::vector;

class Solution
{
public:
    struct SumKey
    {
        int start;
        int end;

        SumKey(int start, int end) : start(start), end(end) {}
        SumKey() : start(0), end(0) {}

        bool operator<(const SumKey& other) const
        {
            if (this->start < other.start) return true;
            if (this->end < other.end) return true;
            return false;
        }
    };

    std::map<SumKey, int> sumMap;

    int maxSum = std::numeric_limits<int>::min();
    void calcSubSum(const vector<int> &nums, int start, int end)
    {
        if (start > end) return;

        int sum = 0;
        if (sumMap.find(SumKey(start, end)) != sumMap.end())
        {
            sum = sumMap[SumKey(start, end)];
        }
        else
        {
            for (int i = start; i <= end; i++)
            {
                sum += nums[i];
            }
            sumMap[SumKey(start, end)] = sum;
        }
        if (sum > maxSum) maxSum = sum;

        calcSubSum(nums, start, end - 1);
        calcSubSum(nums, start + 1, end);
    }

    int maxSubArray(vector<int> &nums)
    {
        calcSubSum(nums, 0, nums.size() - 1);

        return maxSum;
    }
};
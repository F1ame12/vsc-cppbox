#include "../common/std_basic.h"

/**
 * LeetCode 1026 节点与其祖先之间的最大差值
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:

    int max = std::numeric_limits<int>::min();
    std::vector<int> parentVals;

    int maxAncestorDiff(TreeNode *root)
    {
        checkDelta(root);
        return max;
    }

    void checkDelta(TreeNode* root)
    {
        if (!root) return;

        for (const int& val : parentVals)
        {
            unsigned int delta = std::abs(root->val - val);
            if (delta > max) max = delta;
        }

        parentVals.push_back(root->val);

        checkDelta(root->left);
        checkDelta(root->right);

        parentVals.pop_back();
    }
};
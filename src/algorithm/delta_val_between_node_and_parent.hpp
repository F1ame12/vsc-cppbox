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
        return getDelta(root, root->val, root->val);
    }

    int getDelta(TreeNode* root, int min, int max)
    {
        if (root == nullptr) 
            return 0;

        int delta = std::max(std::abs(root->val - min), std::abs(root->val - max));
        min = std::min(min, root->val);
        max = std::max(max, root->val);

        delta = std::max(delta, getDelta(root->left, min, max));
        delta = std::max(delta, getDelta(root->right, min, max));

        return delta;
    }
};
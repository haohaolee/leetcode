#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    int maxPathSum(TreeNode *node)
    {
        if (node == NULL)
           return 0;
        int max = node->val;
        maxHelper(node, max);
        return max;
    }
    
    int maxHelper(TreeNode *node, int &m)
    {
        if (node == NULL)
            return 0;
 
        int sum1 = maxHelper(node->left, m);
        int sum2 = maxHelper(node->right, m);
        
        int val = node->val;
        int ret = val;
        // val will be biggest of (node + left + right) if left or right > 0
        // ret will be biggest of node and node + sum(left) and node + sum(right))
        if (sum1 > 0)
        {
            val += sum1;
            ret += sum1;
        }
        if (sum2 > 0)
        {
            val += sum2;
            ret = std::max(ret, node->val + sum2);
        }

        m = std::max(m, val);

        return ret;
    }

};



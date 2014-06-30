#include <utility>
#include <algorithm>
#include <cstdlib>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return caculate_helper(root) != -1;
    }

    // return value: -1 means not balanced otherwise the depth
    int caculate_helper(TreeNode const* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left = caculate_helper(node->left);
        if (left == -1)
            return -1;
        int right = caculate_helper(node->right);
        if (right == -1)
            return -1;

        bool balance = abs(left - right) > 1 ? false : true;
        if(balance)
            return max(left, right) + 1;

        return -1;
    }

};


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

    int caculate_helper(TreeNode const* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left = caculate_helper(node->left);
        int right = caculate_helper(node->right);

        bool balance = false;
        if (left != -1 && right != -1) {

            balance = abs(left - right) > 1 ? false : true;
            if(balance)
                return max(left, right) + 1;
        }

        return -1;
    }

};


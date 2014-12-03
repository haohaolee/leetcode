/*
 * https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * */
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(std::vector<int> &preorder,
                        std::vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(),
                            inorder.begin(), inorder.end());
    }

private:
    typedef std::vector<int>::const_iterator ConstIt;
    TreeNode *buildTree(ConstIt preorderBegin, ConstIt preorderEnd,
                        ConstIt inorderBegin, ConstIt inorderEnd)
    {
        if (preorderBegin == preorderEnd)
            return 0;

        int rootVal = *preorderBegin;
        TreeNode *root = new TreeNode(rootVal);

        ConstIt it = std::find(inorderBegin, inorderEnd, rootVal);

        int distance = std::distance(inorderBegin, it);
        root->left = buildTree(preorderBegin + 1, preorderBegin + distance + 1,
                                inorderBegin, it);
        root->right = buildTree(preorderBegin + distance + 1, preorderEnd,
                                it + 1, inorderEnd);

        return root;
    }
};

}

TEST(construct_binary_tree_from_preorder_and_inorder_traversal, case1)
{
    std::vector<int> preorder = {7,10,4,3,1,2,8,11};
    std::vector<int> inorder = {4,10,3,1,7,11,8,2};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    EXPECT_EQ(root->val, 7);
    EXPECT_EQ(root->left->val, 10);
    EXPECT_EQ(root->right->val, 2);
    EXPECT_EQ(root->left->left->val, 4);
    EXPECT_EQ(root->right->right, nullptr);
}


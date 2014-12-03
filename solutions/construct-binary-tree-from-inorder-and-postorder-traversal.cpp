/*
 *https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *buildTree(std::vector<int> &inorder,
                        std::vector<int> &postorder) {
       return buildTree(postorder.begin(), postorder.end(),
                        inorder.begin(), inorder.end());
    }

private:
    typedef std::vector<int>::const_iterator ConstIt;
    TreeNode *buildTree(ConstIt postorderBegin, ConstIt postorderEnd,
                        ConstIt inorderBegin, ConstIt inorderEnd)
    {
        if (postorderBegin == postorderEnd)
            return 0;

        int val = *(postorderEnd - 1);
        ConstIt it = std::find(inorderBegin, inorderEnd, val);

        int distance = std::distance(inorderBegin, it);
        TreeNode *root = new TreeNode(val);

        root->left = buildTree(postorderBegin, postorderBegin + distance,
                                inorderBegin, it);
        root->right = buildTree(postorderBegin + distance, postorderEnd - 1,
                                it + 1, inorderEnd);

        return root;
    }
};

}

TEST(construct_binary_tree_from_inorder_and_postorder_traversal, case1)
{
    std::vector<int> postorder = {4,1,3,10,11,8,2,7};
    std::vector<int> inorder = {4,10,3,1,7,11,8,2};

    Solution s;
    TreeNode *root = s.buildTree(inorder, postorder);

    EXPECT_EQ(root->val, 7);
    EXPECT_EQ(root->left->val, 10);
    EXPECT_EQ(root->right->val, 2);
    EXPECT_EQ(root->left->left->val, 4);
    EXPECT_EQ(root->right->right, nullptr);
    
}


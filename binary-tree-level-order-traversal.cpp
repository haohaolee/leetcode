#include <vector>
#include <queue>
#include <utility>

using namespace std;

 //Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};
 
class Solution {
public:
    vector<vector<int> >
        levelOrder(TreeNode *root) {
            vector<vector<int> > m;
            queue<pair<TreeNode*, size_t> > q;

            if(root != 0)
                q.push(make_pair(root, 0));

            while(!q.empty())
            {
                pair<TreeNode*, size_t> p = q.front();
                q.pop();
                TreeNode* node = p.first;
                size_t level = p.second;
                if (level+1 > m.size())
                    m.resize(level + 1);
                m[level].push_back(node->val);
                if (node->left != 0)
                    q.push(make_pair(node->left, level+1));
                if (node->right != 0)
                    q.push(make_pair(node->right, level+1));
            }

            return m;
    }
};


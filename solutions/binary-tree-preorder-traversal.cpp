#include <stack>
#include <vector>
#include <cstddef>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {

		vector<int> result;
		if (root == NULL)
			return result;

		stack<pair<TreeNode *, bool> > node_stack;
		node_stack.push(make_pair(root, false));

		while (!node_stack.empty())
		{
			bool isVisited = node_stack.top().second;
			TreeNode *node = node_stack.top().first;
			node_stack.pop();

			if (isVisited)
			{
				result.push_back(node->val);
			}
			else
			{
				if (node->right != NULL)
					node_stack.push(make_pair(node->right, false));

				if (node->left != NULL)
					node_stack.push(make_pair(node->left, false));
				node_stack.push(make_pair(node, true));
			}
		}
		return result;
	}
};


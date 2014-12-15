#include <cstdlib>
#include <queue>
#include <string>
#include <sstream>
#include <utility>
#include <stdexcept>
using namespace std;

#include "util.h"

void destroy_linked_list(ListNode* head) {
  ListNode* cur = head;

  while (cur) {
    ListNode* next = cur->next;
    delete cur;
    cur = next;
  }
}

string output_linked_list(ListNode* head) {
  string output;
  ListNode* cur = head;

  while (cur) {
    if (!output.empty()) {
      output.append(",");
    }

    output.append(to_string(cur->val));

    cur = cur->next;
  }

  return output;
}

ListNode* build_linked_list(const string& list_data) {
  ListNode* head = NULL, *cur = NULL, *next = NULL;

  // Use stream to split string with delimiter = ",".
  istringstream stream(list_data);
  string token = "";

  // Build the linked list.
  while (getline(stream, token, ',')) {
    next = new ListNode(stoi(token));

    if (cur) {
      cur->next = next;
    }

    cur = next;

    if (head == NULL) {
      head = cur;
    }
  }

  return head;
}


void destroy_tree(TreeNode* root) {
  if (root == NULL)
    return;

  // destroy sub-tree if exists.
  destroy_tree(root->left);
  root->left = NULL;
  destroy_tree(root->right);
  root->right = NULL;

  // desctruct root node.
  delete root;
}

string output_tree(TreeNode* root) {
  string output = "";

  if (root == NULL)
    return output;

  queue<TreeNode*> candidate_list;

  // Enqueue the root node.
  candidate_list.push(root);

  // Iterate each node per level.
  while (!candidate_list.empty()) {
    TreeNode* node = candidate_list.front();
    candidate_list.pop();

    // Add comma for non-first iteration.
    if (!output.empty()) {
      output.append(",");
    }

    // Placehold for empty nodes.
    if (node == NULL) {
      output.append("#");
      continue;
    } else {
      output.append(to_string(node->val));
    }

    // Enqueue children nodes
    candidate_list.push(node->left);
    candidate_list.push(node->right);
  }

  // Remove the left trailing "#,".
  output = trim(output, "#,");
  // Remove the right trailing "#,".
  output = trim(output, ",#");

  return output;
}

TreeNode* build_tree(const std::string& tree_data) {
  TreeNode * root = NULL;

  // Empty tree
  if (tree_data.empty() || tree_data[0] == '#')
    return root;

  // Use stream to split string with delimiter = ",".
  istringstream stream(tree_data);
  string token = "";

  // Queue used to store the candidate nodes to do per-level traversal.
  queue<TreeNodeInfo> candidate_nodes;

  // Enqueue the root node.
  candidate_nodes.push(TreeNodeInfo(NULL, TreeNodeType::Root));

  // Build the tree per-level.
  while (!candidate_nodes.empty() && getline(stream, token, ',')) {
    auto candidate_node = candidate_nodes.front();
    candidate_nodes.pop();

    auto parent_node = candidate_node.first;
    TreeNodeType node_type = candidate_node.second;

    // Check if current character in tree data buffer is valid one.
    if (token == "#")
      continue;

    // Create the node and update the tree structure.
    auto node = new TreeNode(stoi(token));
    switch (node_type) {
      case TreeNodeType::Root:
        root = node;
        break;
      case TreeNodeType::LeftChild:
        parent_node->left = node;
        break;
      case TreeNodeType::RightChild:
        parent_node->right = node;
      default:
        break;
    };

    candidate_nodes.push(TreeNodeInfo(node, TreeNodeType::LeftChild));
    candidate_nodes.push(TreeNodeInfo(node, TreeNodeType::RightChild));
  }

  return root;
}

string trim(const string& data, const string& pattern) {
  // [start_pos, end_pos]
  string trimed = "";
  string::size_type start_pos = data.find_first_not_of(pattern);
  string::size_type end_pos = data.find_last_not_of(pattern);

  if (start_pos == string::npos || end_pos == string::npos)
    return trimed;

  return data.substr(start_pos, end_pos - start_pos + 1);
}

//bool operator==(const std::vector<std::vector<int>>& left,
//                const std::vector<std::vector<int>>& right) {
//  size_t left_matrix_size = left.size();
//  size_t right_matrix_size = right.size();
//
//  if (left_matrix_size != right_matrix_size)
//    return false;
//
//  bool ret = true;
//  for (size_t i = 0; i < left_matrix_size && ret; ++i) {
//    size_t left_vector_size = left[i].size();
//    size_t right_vector_size = right[i].size();
//
//    if (left_vector_size != right_vector_size) {
//      ret = false;
//      break;
//    }
//
//    for (size_t j = 0; j < left_vector_size; ++j) {
//      if (left[i][j] != right[i][j]) {
//        ret = false;
//        break;
//      }
//    }
//  }
//
//  return ret;
//}
//

vector<ListNode *> build_linked_list_of_vector(string const& data) {
	vector<ListNode*> lists;
	string::size_type start = 0, end = 0;
	while (true) {
		start = data.find_first_of('{', start);
		if (start == string::npos)
			break;

		end = data.find_first_of('}', start + 1);
		if (end == string::npos)
			throw runtime_error("no matching }");
		auto node = build_linked_list(data.substr(start + 1, end - start - 1));
		lists.push_back(node);
		start = end + 1;
	}

	return lists;
}

void destroy_linked_list_of_vector(vector<ListNode *> const &lists) {
    for (auto l : lists)
    {
        destroy_linked_list(l);
    }
}

string output_linked_list_of_vector(vector<ListNode*> const& lists) {
    ostringstream ss;
    ss << '[';

    if (!lists.empty()) {
        auto it = begin(lists);
        auto const last = end(lists) - 1;
        while (it != last) {
            ss << '{' << output_linked_list(*it) << "},";
			++it;
        }

        ss << '{' << output_linked_list(*last) << '}';
    }

    ss << ']';

    return ss.str();
}




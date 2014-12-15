#include <algorithm>
#include <string>
using namespace std;

#include <gtest/gtest.h>

#include "util.h"

namespace {
  TEST(UtilTest, Case1) {
    string tree_data = "1,2,2,3,#,#,3,4,#,#,4";
    TreeNode* root = NULL;

    root = build_tree(tree_data);
    string output = output_tree(root);
    EXPECT_EQ(tree_data, output);
    destroy_tree(root);
  };

  TEST(UtilTest, Case2) {
    string tree_data = "5,4,8,11,#,13,4,7,2,#,#,5,1";
    TreeNode* root = NULL;

    root = build_tree(tree_data);
    string output = output_tree(root);
    EXPECT_EQ(tree_data, output);
    destroy_tree(root);
  };

  TEST(UtilTest, Case3) {
      string linked_list_data = "1,3,2,6,5,8";
      ListNode* root = build_linked_list(linked_list_data);

      string output = output_linked_list(root);
      EXPECT_EQ(linked_list_data, output);
  };

  TEST(UtilTest, Case4) {
      string data = "[{1,2},{3,4},{}]";
      std::vector<ListNode*> vec = build_linked_list_of_vector(data);

      string output = output_linked_list_of_vector(vec);
      EXPECT_EQ(data, output);
  };
}


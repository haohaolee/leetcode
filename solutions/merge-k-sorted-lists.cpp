/*
 *https://oj.leetcode.com/problems/merge-k-sorted-lists/
 * */
#include <vector>
#include <algorithm>
#include <functional>
#include <gtest/gtest.h>
#include <util.h>

namespace {
class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        std::size_t size = lists.size();
        if (size == 0)
            return 0;

        ListNode *root = 0;
        ListNode **pNode = &root;

        std::vector<int> heap;
        heap.reserve(size);

        while(true)
        {
            for (std::vector<ListNode *>::iterator it = lists.begin();
                    it != lists.end(); )
            {
                ListNode* & n = *it;
                if (n != 0)
                {
                    heap.push_back(n->val);
                    std::push_heap(heap.begin(), heap.end(), std::greater<int>());
                    n = n->next;
                    ++it;
                }
                else
                    it = lists.erase(it);

            }

            if (heap.empty())
                break;

            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            int val = heap.back();
            heap.pop_back();
            *pNode = new ListNode(val);
            pNode = &((*pNode)->next);
        }

        return root;
    }
};

}


TEST(merge_k_sorted_lists, case1)
{
    std::string data = "[{7},{49},{73},{58},{30},{72},{44},{78},{23},{9}]";
    std::string result = "7,9,23,30,44,49,58,72,73,78";

    std::vector<ListNode*> vec = build_linked_list_of_vector(data);
    ListNode* root = Solution().mergeKLists(vec);

    std::string output = output_linked_list(root);
    EXPECT_EQ(result, output);

    destroy_linked_list_of_vector(vec);
    destroy_linked_list(root);

}

TEST(merge_k_sorted_lists, case2)
{
    std::string data = "[{7,8},{49,100},{73},{44,88},{78,79},{23,67},{9,10}]";
    std::string result = "7,8,9,10,23,44,49,67,73,78,79,88,100";

    std::vector<ListNode*> vec = build_linked_list_of_vector(data);
    ListNode* root = Solution().mergeKLists(vec);

    std::string output = output_linked_list(root);
    EXPECT_EQ(result, output);

    destroy_linked_list_of_vector(vec);
    destroy_linked_list(root);

}



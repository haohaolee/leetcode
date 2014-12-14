/*
 *https://oj.leetcode.com/problems/merge-k-sorted-lists/
 * */
#include <vector>
#include <algorithm>
#include <functional>
#include <gtest/gtest.h>

namespace {
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
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


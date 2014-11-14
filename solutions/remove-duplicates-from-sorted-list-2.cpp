#include <iostream>
#include <utility>
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode **pNode = &head;
        while (*pNode != NULL)
        {
            std::pair<ListNode *, bool> re = iterateAndJudge(*pNode);
            if (re.second)
            {
                *pNode = re.first;
            }
            else
            {
                pNode = &((*pNode)->next);
            }
        }

        return head;
    }

    std::pair<ListNode *, bool> iterateAndJudge(ListNode *node)
    {
        std::size_t count = 0;
        while (node->next != NULL && node->val == node->next->val)
        {
            count++;
            node = node->next;
        }
        return std::make_pair(node->next, count != 0);
    }
};

/*int main()
{
    ListNode head(1);
    ListNode n1(2);
    ListNode n2(2);
    ListNode n3(3); 
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;

    ListNode *newhead = Solution().deleteDuplicates(&head);

    while (newhead != NULL)
    {
        std::cout << newhead->val << ' ';
        newhead = newhead->next;
    }
    std::cout.flush();
}
*/


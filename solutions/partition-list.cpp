#include <cstddef>
#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *low = NULL; ListNode **p1 = &low;
        ListNode *high = NULL; ListNode **p2 = &high;
        while (head != NULL)
        {
            if (head->val < x)
            {
                *p1 = head; p1 = &(head->next);
            }
            else
            {
                *p2 = head; p2 = &(head->next);
            }
            head = head->next;
        }
        *p1 = high;
        *p2 = NULL;

        return low;
    }
};

/*int main()
{
    ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode *head = Solution().partition(&n1, 3);

    while (head != NULL)
    {
        std::cout << head->val << ' ';
        head = head->next;
    }
    std::cout.flush();

} */


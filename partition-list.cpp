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
        ListNode *part1 = NULL, *head1 = NULL;
        ListNode *part2 = NULL, *head2 = NULL;
        ListNode *current = head;
        while (current != NULL)
        {
            if (current->val < x)
            {
                if (head1 == NULL)
                {
                    head1 = part1 = current;
                }
                else
                {
                    part1->next = current;
                    part1 = current;
                }
            }
            else
            {
                if (head2 == NULL)
                {
                    head2 = part2 = current;
                }
                else
                {
                    part2->next = current;
                    part2 = current;
                }
            }
            current = current->next;
        }

        if (part2 != NULL)
            part2->next = NULL;

        if (head1 != NULL)
        {
            part1->next = head2;
            return head1;
        }

        return head2;
    }
};

int main()
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

}


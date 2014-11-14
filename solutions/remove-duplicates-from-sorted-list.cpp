#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	ListNode *node = head;
    	while (node != NULL && node->next != NULL)
    	{
    		if (node->next->val == node->val)
    		{
    			node->next = node->next->next;
    		}
    		else
    		{
    			node = node->next;
    		}
    	}
    	return head;
    }
};


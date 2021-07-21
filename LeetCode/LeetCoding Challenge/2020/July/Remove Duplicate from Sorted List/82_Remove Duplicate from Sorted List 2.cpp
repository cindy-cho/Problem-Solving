// Runtime: 8 ms, faster than 64.33% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 11.2 MB, less than 55.14% of C++ online submissions for Remove Duplicates from Sorted List II.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        //use two pointers, slow - track the node before the dup nodes,
        // fast - to find the last node of dups.
        ListNode *dummy = new ListNode(0), *fast = head, *slow = dummy;
        slow->next = fast;
        while (fast != NULL)
        {
            while (fast->next != NULL && fast->val == fast->next->val)
            {
                fast = fast->next; //while loop to find the last node of the dups.
            }
            if (slow->next != fast)
            {                            //duplicates detected.
                slow->next = fast->next; //remove the dups.
                fast = slow->next;       //reposition the fast pointer.
            }
            else
            { //no dup, move down both pointer.
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};
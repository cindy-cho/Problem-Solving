// Runtime: 12 ms, faster than 50.54% of C++ online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 11.5 MB, less than 73.78% of C++ online submissions for Remove Duplicates from Sorted List.

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead=head;
        ListNode *newCrnt;
        if(newHead==NULL || newHead->next==NULL) return newHead;
        ListNode *crnt = head;
        newCrnt = newHead;
        while(crnt!=NULL){
            if(crnt->val != newCrnt->val){
                newCrnt->next = crnt;
                newCrnt = newCrnt->next;
            }
            crnt = crnt->next;
        }
        if(newCrnt!=NULL && newCrnt->next!=NULL) newCrnt->next = NULL;
        
        return newHead;
    }
};

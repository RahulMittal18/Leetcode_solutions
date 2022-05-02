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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode* dummy = new ListNode(-1,head);
        ListNode *prev=dummy, *curr=head, *nextt=NULL;
        while(curr && curr->next){
            nextt = curr->next;
            curr->next = nextt->next;
            nextt->next = curr;
            prev->next=nextt;
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }

};
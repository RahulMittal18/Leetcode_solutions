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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode();
    ListNode* dp = dummy;
    ListNode* newhead = new ListNode();
    ListNode* newp = newhead;
    while(head){
        if(head->val<x){
            newp->next = head;
            newp=newp->next;
        }
        else{
            dp->next = head;
            dp=dp->next;
        }
        head=head->next;
    } 
    newp->next=dummy->next;
    dp->next=nullptr;
    return newhead->next;
    }
};
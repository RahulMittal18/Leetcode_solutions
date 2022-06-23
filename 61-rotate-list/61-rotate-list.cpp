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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=0;
        ListNode* temp =head;
        if(k==0 || !head || !head->next) return head;
        while(temp){
            temp=temp->next;
            count++;
        }
        k=k%count;
        if(k==0) return head;
        ListNode *fast=head,*slow=head;
        while(k--) fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* ans = slow->next;
        fast->next=head;
        slow->next=NULL;
        return ans;
    }
};
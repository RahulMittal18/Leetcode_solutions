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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head or !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        n-=1;
        while(n--) fast=fast->next;
        if(fast->next){
            fast=fast->next;
            
            while(fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            slow->next=slow->next->next;
        }
        else{
            return head->next;
        }
        return head;
    }
};
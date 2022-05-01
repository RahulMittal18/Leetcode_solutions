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
        if(!head or !head->next) return head;
        ListNode* temp=new ListNode(-101);
        ListNode* ans = temp;
        ListNode* prev = temp;

        temp->next= head;
        temp=temp->next;
        while(temp and temp->next){
            if(temp->val==temp->next->val){
                while(temp->next and temp->val==temp->next->val){
                    temp=temp->next;
                }
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return ans->next;
    }
};
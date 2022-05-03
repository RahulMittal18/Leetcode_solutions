class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next) return;
        
        // Finding middle of linked list
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // Reversing the second half of the linked list
        ListNode* prev=NULL;
        ListNode* curr = slow->next;
        while(curr){
            ListNode* nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nextt;
        }
        slow->next = NULL;
        
        // Merge two lists 
        ListNode* head1=head;
        ListNode* head2=prev;
        while(head2){
            ListNode* temp = head1->next;
            head1->next = head2;
            head1=head1->next;
            head2= temp;
        }
        
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* ptr1=head1;
        ListNode* ptr2=head2;
        int l1=0,l2=0;
        while(ptr1){
            l1+=1;
            ptr1=ptr1->next;
        }
        while(ptr2){
            l2+=1;
            ptr2=ptr2->next;
        }
        if(l1>l2){
            while(l1-l2>0){
                head1=head1->next;
                l1-=1;
            }
        }
        else{
            while(l2-l1>0){
                head2=head2->next;
                l2-=1;
            }
        }
        
        while(head1){
            if(head1==head2){
                return head1;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) return head;
        ListNode *prev = NULL;
        ListNode *curr = head, *nextt ;
        int c = right-left+1;
        while(left-- > 1){
            prev = curr;
            curr=curr->next;
        }
        
        ListNode *conn = prev, *tail = curr;

        while(c--){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        
        if (conn != NULL) conn->next = prev;
        else head = prev;
        
        tail->next = curr;
        return head;
    }
};
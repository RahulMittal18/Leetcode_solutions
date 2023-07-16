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
    ListNode* solve(ListNode* head, int &mx){
        if(!head) return head;
        if(!head->next) {
            mx = max(mx,head->val);
            return head;
        }
        head->next = solve(head->next,mx);
        if(mx>head->val) return head->next;
        mx=max(mx,head->val);
        return head;
    }
    
    ListNode* removeNodes(ListNode* head) {
        int mx = 0;
        return solve(head,mx);
    }
};
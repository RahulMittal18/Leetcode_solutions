/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp= temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random==NULL) temp->next->random = NULL;
            else temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* head1 = head;
        temp = head->next;
        Node* ans = temp;
        
        while(head1 && head1->next ){
            head1->next = head1->next->next;
            if(temp->next)
            temp->next = head1->next->next;
            head1=head1->next;
            temp = temp->next;
        }

        return ans;
    }
};
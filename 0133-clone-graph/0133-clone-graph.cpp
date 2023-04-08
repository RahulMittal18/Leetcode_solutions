/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<Node*,Node*> visited;          
       
    Node* copy(Node* node){
            if(visited.find(node)==visited.end()){
                
            
            visited[node]=new Node(node->val);
            for(int i=0;i<node->neighbors.size();i++){
                visited[node]->neighbors.push_back(copy((node->neighbors)[i]));
            }
                
            }
            return visited[node];
            
        }
        
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        
        return copy(node);
            
    }
};
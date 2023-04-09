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
    
    Node* dfs(Node *src,map<Node*,Node*>&m){
        
        if(m.count(src) != 0){
            return m[src];
        }
        
        Node *temp = new Node(src->val);
        m[src] = temp;
        
        for(auto q:src->neighbors){
            temp->neighbors.push_back(dfs(q,m));
        }
        
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL;
        
        
        map<Node*,Node*>m;
        
        return dfs(node,m);
    }
};




















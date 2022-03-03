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
    
    Node* dfs(Node* curNode,unordered_map<Node*,Node*>& mp){
        
        Node* newNode = new Node(curNode->val);
        mp[curNode] = newNode;
        
        for(auto& nbr : curNode->neighbors){
            
            
            if(mp.find(nbr) != mp.end()){                
                newNode->neighbors.push_back(mp[nbr]);
            }else{
                newNode->neighbors.push_back(dfs(nbr,mp));
            }
            
        }
        
    
        return newNode;
        
        
    }
    
    Node* cloneGraph(Node* node) {
        
        
        if( node == nullptr)
            return nullptr;
        
        unordered_map<Node*,Node*> mp;
        
        if(node->neighbors.size()==0){
            return new Node(node->val);
        }
        
        
        
        
        return dfs(node,mp);
        
    }
};
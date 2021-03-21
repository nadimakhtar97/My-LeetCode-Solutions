/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
      
      vector<int> res;
      pre(root,res);
      return res;
    }
  
    void pre(Node* root,vector<int>& res)
    {
      if(root==nullptr)
        return;
      
      int n = root->children.size();
      
      res.push_back(root->val);
      for(int i=0;i<n;i++)
      {
        pre(root->children[i],res);
      }
    }
};
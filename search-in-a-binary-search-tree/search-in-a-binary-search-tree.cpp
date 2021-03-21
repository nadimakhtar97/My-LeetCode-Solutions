/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
      
      if(root==nullptr)
        return nullptr;
      
      TreeNode* node = nullptr;
      
      if(val == root->val)
      {
        node = root;
        return node;
      }
      
      if(val < root->val)
      {
        node = searchBST(root->left,val);
        if(node && node->val == val)
          return node;
      }
      
      if(val > root->val)
      {
        node = searchBST(root->right,val);
        if( node && node->val == val)
          return node;       
      }
      
      return node?node:nullptr;
        
    }
};
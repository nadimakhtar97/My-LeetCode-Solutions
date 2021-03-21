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
    TreeNode* bstToGst(TreeNode* root) {
      
      int mx = 0;
      toGst(root,mx);
      return root;
    }
  
    void toGst(TreeNode* root,int& mx)
    {
      if(root==nullptr)
        return;
      
      
      toGst(root->right,mx);
      root->val += mx;
      mx = root->val;
      toGst(root->left,mx);
      
    }
};
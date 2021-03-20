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


// Let children know who their grandparent is.


class Solution {
public:
    int sumEvenGrandparent(TreeNode* root,int parent = 1,int grandParent=1) {
     
      if(root == nullptr)
        return 0;
      
      int sum = 0;
      int left = sumEvenGrandparent(root->left,root->val,parent);
      int right = sumEvenGrandparent(root->right,root->val,parent);
      
      if(grandParent%2==0)
        sum += root->val;
        
      
      return left+right+sum;
      
    }
};
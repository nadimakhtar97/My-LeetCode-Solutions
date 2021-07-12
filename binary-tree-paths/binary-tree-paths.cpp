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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> paths;
        string path = "";
        dfs(root,path,paths);
        return paths;
    }
    
    void dfs(TreeNode* root,string path,vector<string>& paths)
    {
        if(root==nullptr)
            return;

        if(root->left == nullptr && root->right==nullptr){
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }
        
        path += to_string(root->val) + "->";
        
        dfs(root->left,path,paths);
        dfs(root->right,path,paths);
        
    }
};
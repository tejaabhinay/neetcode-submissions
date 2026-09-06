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
    void helper(TreeNode* root,vector<int> &ans,int level,int &maxlevel){
        if(root==NULL)
            return;
        if(level>maxlevel){
            ans.push_back(root->val);
            maxlevel=level;
        }
        helper(root->right,ans,level+1,maxlevel);
        helper(root->left,ans,level+1,maxlevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level=0;
        int maxlevel=-1;
        helper(root,ans,level,maxlevel);
        return ans;
    }
};

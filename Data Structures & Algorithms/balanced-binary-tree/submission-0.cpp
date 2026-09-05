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
    int helper(TreeNode* root,int &dia,int &maxdia){
        if(root==NULL){
            return 0;
        }
        int lh=helper(root->left,dia,maxdia);
        int rh=helper(root->right,dia,maxdia);
        dia=abs(lh-rh);
        maxdia=max(dia,maxdia);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int maxdia=0;
        int dia=0;
        helper(root,dia,maxdia);
        if(maxdia>1)
            return false;
        else return true;
    }
};

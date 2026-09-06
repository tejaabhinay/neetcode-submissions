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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int currLevel=0;
        while(!q.empty()){
            int len=q.size();
            ans.push_back({});
            for(int i=0;i<len;i++){
                TreeNode* first=q.front();
                q.pop();
                ans[currLevel].push_back(first->val);
                if(first->left!=NULL)
                    q.push(first->left);
                if(first->right!=NULL)
                    q.push(first->right);
            }
            currLevel++;
        }   
        return ans;
    }
};

class Solution {
public:
    void backtracking(vector<int>& nums,vector<vector<int>> &ans,vector<int> &current,int i){
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        backtracking(nums,ans,current,i+1);
        current.pop_back();
        backtracking(nums,ans,current,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtracking(nums,ans,current,0);
        return ans;
    }
};

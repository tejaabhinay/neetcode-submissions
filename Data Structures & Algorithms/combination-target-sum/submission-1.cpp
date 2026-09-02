class Solution {
public:
    void backtracking(vector<int>& nums, int target,vector<vector<int>> &ans,vector<int> current,int i){
        if(target==0){
            ans.push_back(current);
            return;
        }
        if(target<0||i==nums.size()){
            return;
        }
        if(nums[i]>target)
            return;
        current.push_back(nums[i]);
        backtracking(nums,target-nums[i],ans,current,i);
        current.pop_back();
        backtracking(nums,target,ans,current,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        int sum=0;
        sort(nums.begin(),nums.end());
        backtracking(nums,target,ans,current,sum);
        return ans;
    }
};

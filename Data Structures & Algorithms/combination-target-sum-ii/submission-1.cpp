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
        for(int j = i; j < nums.size(); j++) {
    if(j > i && nums[j] == nums[j-1])
        continue;

    if(nums[j] > target)
        break;

    current.push_back(nums[j]);

    backtracking(nums, target - nums[j], ans, current, j + 1);

    current.pop_back();
}
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,ans,current,sum);
        return ans;
    }
};

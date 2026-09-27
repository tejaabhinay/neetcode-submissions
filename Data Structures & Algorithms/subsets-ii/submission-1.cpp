class Solution {
public:
    void backtracking(vector<int>& nums,vector<vector<int>> &ans,vector<int> &current,int i){
        ans.push_back(current);
        for(int j=i;j<nums.size();j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            current.push_back(nums[j]);
            backtracking(nums,ans,current,j+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(),nums.end());
        backtracking(nums,ans,current,0);
        return ans;
    }
};

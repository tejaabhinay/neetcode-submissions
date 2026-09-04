class Solution {
public:
    void backtracking(vector<int>& nums,vector<vector<int>> &ans,vector<int> &current,vector<bool> used){
                    if(current.size()==nums.size()){
            ans.push_back(current);
            return;
            }
        for(int j=0;j<nums.size();j++){

            if(used[j])
                continue;
            used[j]=true;
            current.push_back(nums[j]);
            backtracking(nums,ans,current,used);
            current.pop_back();
            used[j]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(),false);
        backtracking(nums,ans,current,used);
        return ans;
    }
};

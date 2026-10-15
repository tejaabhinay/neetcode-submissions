class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Compare values (second element of pair)
        });
        vector<int>ans;
        for(auto p:vec){
            if(k!=0){
                ans.push_back(p.first);
                k--;
            }
        }
        return ans;
    }
};

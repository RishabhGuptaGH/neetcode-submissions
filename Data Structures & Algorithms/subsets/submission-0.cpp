class Solution {
public:
    vector<vector<int>> f(vector<int>& arr, int idx, vector<vector<vector<int>>>& dp){
        if(arr.size() == idx)return {};

        if(dp[idx].size() > 0)return dp[idx];

        // Accept
        vector<vector<int>> ans1 = f(arr, idx+1, dp);
        for(auto& i: ans1)i.push_back(arr[idx]);
        ans1.push_back({arr[idx]});

        // Reject
        vector<vector<int>> ans2 = f(arr, idx+1, dp);

        vector<vector<int>> fa;
        for(auto& i: ans1)fa.push_back(i);
        for(auto& i: ans2)fa.push_back(i);

        return dp[idx] = fa;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<vector<int>>> dp;
        for(int i = 0; i < nums.size(); i++){
            vector<vector<int>> v1;
            dp.push_back(v1);
        }
        vector<vector<int>> ans = f(nums, 0, dp);
        ans.push_back({});

        return ans;
    }
};
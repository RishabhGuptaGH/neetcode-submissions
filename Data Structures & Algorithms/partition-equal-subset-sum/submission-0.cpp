class Solution {
public:

    bool f(vector<int>& arr, int target, int idx, vector<vector<int>>& dp){
        if(target == 0)         return true;
        if(idx == arr.size())   return false;

        if(dp[target][idx] != -1)return dp[target][idx];

        bool ans = false;
        // Accept
        if(arr[idx] <= target)ans = f(arr, target-arr[idx], idx+1, dp);

        // Reject
        ans = ans || f(arr, target, idx+1, dp);

        return dp[target][idx] = ans;
    }

    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp;

        int sum = 0;
        for(int i = 0; i < nums.size(); i++)sum += nums[i];

        for(int i = 0; i <= sum; i++)dp.push_back(vector<int>(nums.size(), -1));

        if(sum % 2 != 0)return false;
        
        return f(nums, sum/2, 0, dp);
    }
};

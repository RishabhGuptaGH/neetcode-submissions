int f(int idx, int amount, vector<int>& v1, vector<vector<int>>& dp){
    if(amount == 0)return 1;
    if(idx < 0)return 0;
    if(dp[idx][amount] != -1)return dp[idx][amount];

    int acc = 0, rej = 0;
    
    // Accept
    if(v1[idx] <= amount){
        acc = f(idx, amount - v1[idx], v1, dp);
    }

    // Reject
    rej = f(idx-1, amount, v1, dp);

    return dp[idx][amount] = acc+rej;
}

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());

        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        return f(coins.size()-1, amount, coins, dp);
    }
};
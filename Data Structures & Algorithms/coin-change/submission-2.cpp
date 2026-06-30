int f(int amount, vector<int>& coins, vector<int>& dp){
    if(amount == 0)return 0;
    if(dp[amount] != -1)return dp[amount];
    
    int ans = INT32_MAX-1;
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] > amount)break;
        ans = min(ans, f(amount-coins[i], coins, dp));
    }
    return dp[amount] = ans + 1;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = f(amount, coins, dp);
        if(ans == INT32_MAX)ans = -1;

        return ans;
    }
};

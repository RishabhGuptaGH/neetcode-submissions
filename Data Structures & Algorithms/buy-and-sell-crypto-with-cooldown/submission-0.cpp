int f(int idx, vector<int>& prices, vector<int>& dp){
    if(idx <= 0)return 0;

    if(dp[idx] != -1)return dp[idx];

    int ans = 0;
    for(int i = 0; i < idx; i++){
        ans = max(ans, f(i, prices, dp));
    }

    for(int i = 0; i < idx; i++){
        ans = max(ans, f(i-2,prices, dp) + prices[idx] - prices[i]);
    }

    return dp[idx] = ans;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), -1);

        dp[0] = 0;

        int a = f(prices.size()-1, prices, dp);
        for(auto i: dp)cout << i << " ";

        return a;
    }
};
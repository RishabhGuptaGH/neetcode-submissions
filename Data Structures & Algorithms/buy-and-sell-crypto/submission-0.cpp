class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0, pp = prices[0];

        for(int i = 1; i < prices.size(); i++){
            p = max(p, prices[i] - pp);
            if(prices[i] - pp < 0)pp = prices[i];
        }
        return p;
    }
};

bool f(string& s, vector<string>& wordDict, int idx, vector<int>& dp){
    if(idx < 0)return true;

    if(dp[idx] != -1)return dp[idx];

    bool ans = false;

    for(int i = 0; i <= idx; i++){
        // Split in [0,i-1], [i,idx]
        string post;
        bool preAns = f(s, wordDict, i-1, dp);

        if(preAns){
            for(int j = i; j <= idx; j++)post += s[j];
            for(auto j: wordDict){
                if(j==post){
                    ans = true;
                    break;
                }
            }
        }
    }

    return dp[idx] = ans;
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return f(s, wordDict, s.size()-1, dp);
    }
};
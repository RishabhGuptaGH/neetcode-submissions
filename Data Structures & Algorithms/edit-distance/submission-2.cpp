int f(int x, int y, string& s1, string& s2, vector<vector<int>>& dp){
    if(x==-1 && y==-1)return dp[x+1][y+1] = 0;
    if(x == -1)return dp[x+1][y+1] = f(x,y-1,s1,s2,dp)+1;
    if(y == -1)return dp[x+1][y+1] = f(x-1,y,s1,s2,dp)+1;

    if(dp[x+1][y+1] != -1)return dp[x+1][y+1];

    return dp[x+1][y+1] = min({f(x-1,y,s1,s2,dp)+1, f(x,y-1,s1,s2,dp)+1, f(x-1,y-1,s1,s2,dp)+1-(int)(s1[x]==s2[y])});
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));

        int ans = f(word1.size()-1, word2.size()-1, word1, word2, dp);

        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

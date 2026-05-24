class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;

        int m = text1.size();
        int n = text2.size();

        for(int i = 0; i < m; i++)dp.push_back(vector<int>(n, 0));
        int v = 0;
        for(int i = 0; i < m; i++){
            if(text1[i]==text2[0]){
                v = 1;
            }   
            dp[i][0] = v;
        }
        v = 0;
        for(int i = 0; i < n; i++){
            if(text2[i]==text1[0]){
                v = 1;
            }
            dp[0][i] = v;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(int)(text1[i]==text2[j])});
            }
        }
        return dp[m-1][n-1];
    }
};

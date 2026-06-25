bool f(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
    if(i < 0 || j < 0)return false;
    if(dp[i][j] != -1)return dp[i][j];

    if((f(i-1, j, s1, s2, s3, dp) && s1[i-1] == s3[i+j-1]) || (f(i, j-1, s1, s2, s3, dp) && s2[j-1] == s3[i+j-1]))return dp[i][j] = true;
    return dp[i][j] = false;
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));

        if(s1.size()+s2.size() != s3.size())return false;
        if(s1.size()==0 && s2.size()==0)return true;
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s3[i])dp[i+1][0]=1;
            else break;
        }
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == s3[i])dp[0][i+1]=1;
            else break;
        }

        bool a = f(s1.size(), s2.size(), s1, s2, s3, dp);

        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++)cout << dp[i][j] << " ";
            cout << endl;
        }
        return a;
    }
};
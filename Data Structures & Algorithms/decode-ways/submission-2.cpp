int f(string& s, int idx, vector<int>& dp){
    if(idx<0)return 0;

    if(idx == 0)return 1;

    if(dp[idx] != -1)return dp[idx];

    // 0 -> Prev has to be 1 or 2 else invalid
    if(s[idx] == '0'){
        if(idx>=2)return dp[idx] = f(s, idx-2, dp);
        else return 1;
    }

    // 1 - 6 -> If prev 1 or 2 f(idx-2)+f(idx-1), else f(idx-1) 
    else if(49 <= s[idx] && 54 >= s[idx]){
        if(idx >= 2){
            if(s[idx-1] == '1' || s[idx-1] == '2'){
                return dp[idx] =  f(s, idx-1, dp) + f(s, idx-2, dp);
            }
            else{
                return dp[idx] =  f(s, idx-1, dp);
            }
        }
        else{
            if(s[idx-1] == '1' || s[idx-1] == '2'){
                return dp[idx] = 2;
            }
            else{
                return dp[idx] = 1;
            }
        }
    }
    // 7 - 9 -> If prev 1 f(idx-2) + f(idx-1), else f(idx-1)
    else{
        if(idx >= 2){
            if(s[idx-1] == '1'){
                return dp[idx] =  f(s, idx-1, dp) + f(s, idx-2, dp);
            }
            else{
                return dp[idx] =  f(s, idx-1, dp);
            }
        }
        else{
            if(s[idx-1] == '1'){
                return dp[idx] =  2;
            }
            else{
                return dp[idx] =  1;
            }
        }
    }
}

class Solution {
public:
    int numDecodings(string s) {
        bool valid = true;

        if(s[0] == '0')valid = false;

        for(int i = 1; i < s.size(); i++){
            if(s[i]=='0' && s[i-1] != '1' && s[i-1] != '2')valid = false;
        }

        if(!valid)return 0;

        vector<int> dp(s.size(), -1);

        return f(s, s.size()-1, dp);
    }
};

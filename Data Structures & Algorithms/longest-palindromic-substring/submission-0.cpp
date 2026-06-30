class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int fb = 0, fe = 0;

        // Odd
        for(int i = 0; i < n; i++){
            int b = i; int e = i;

            while(b >= 0 && e < s.size()){
                if(s[b]==s[e]){
                    b--;
                    e++;
                }
                else break;
            }
            b++;
            e--;
            if(e-b+1 > fe-fb+1){
                fb = b;
                fe = e;
            }
        }


        // Even
        for(int i = 0; i < n; i++){
            int b = i-1; int e = i;

            while(b >= 0 && e < s.size()){
                if(s[b]==s[e]){
                    b--;
                    e++;
                }
                else break;
            }
            b++;
            e--;
            if(e-b+1 > fe-fb+1){
                fb = b;
                fe = e;
            }
        }

        string ans = "";

        for(int i = fb; i <= fe; i++)ans += s[i];

        return ans;
    }
};
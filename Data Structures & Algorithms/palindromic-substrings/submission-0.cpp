class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int c = 0;

        // Odd
        for(int i = 0; i < n; i++){
            int b = i; int e = i;

            while(b >= 0 && e < s.size()){
                if(s[b]==s[e]){
                    b--;
                    e++;
                    c++;
                }
                else break;
            }
        }


        // Even
        for(int i = 0; i < n; i++){
            int b = i-1; int e = i;

            while(b >= 0 && e < s.size()){
                if(s[b]==s[e]){
                    b--;
                    e++;
                    c++;
                }
                else break;
            }
        }

        return c;
    }
};
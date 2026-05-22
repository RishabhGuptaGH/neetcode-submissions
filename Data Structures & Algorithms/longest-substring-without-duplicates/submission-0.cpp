class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;

        vector<int> idx(256,-1);
        for(int i = 0; i < s.size(); i++){
            if(idx[(int)s[i]] == -1){
                idx[(int)s[i]] = i;
            }
            else{
                start = max(idx[(int)s[i]]+1,start);
                idx[(int)s[i]] = i;
            }
            if(maxLen < i-start+1)maxLen = i-start+1;
        }
        return maxLen;
    }
};
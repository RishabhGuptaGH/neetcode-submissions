class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> m2;

        int u = 0;
        for(int i = 0; i < t.size(); i++){
            if(m2.find(t[i]) == m2.end()){
                m2[t[i]] = 1;
                u++;
            }
            else m2[t[i]]++;
        }
        int start,end, minLen = INT32_MAX;
        for(int s1 = 0; s1 < s.size(); s1++){
            int v = 0;
            map<int,int> m1;
            for(int i = s1; i < s.size(); i++){
                if(m1.find(s[i]) == m1.end())m1[s[i]] = 1;
                else m1[s[i]]++;

                if(m2.find(s[i]) != m2.end())if(m2[s[i]] == m1[s[i]])v++;
                if(u==v){
                    if(i-s1 + 1 < minLen){
                        minLen = i-s1+1;
                        start = s1;
                        end = i;
                        break;
                    }
                }
            }
        }
        if(minLen == INT32_MAX)return "";
        return s.substr(start, minLen);
    }
};

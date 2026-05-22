class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1, m2;

        bool ans = true;
        for(auto i: s){
            if(m1.find(i) == m1.end())m1[i]=1;
            else m1[i]++;
        }
        for(auto i: t){
            if(m2.find(i) == m2.end())m2[i]=1;
            else m2[i]++;
        }

        for(auto i: m1){
            if(m2.find(i.first) == m2.end())ans = false;
            else if (m2[i.first] != i.second)ans = false;
        }
        for(auto i: m2){
            if(m1.find(i.first) == m1.end())ans = false;
            else if (m1[i.first] != i.second)ans = false;
        }
        return ans;
    }
};

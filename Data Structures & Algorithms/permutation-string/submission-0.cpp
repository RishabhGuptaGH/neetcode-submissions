class Solution {
public:

    bool allZeros(vector<int>& v1){
        for(int i = 0; i < v1.size(); i++)if(v1[i] != 0)return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);

        bool ans = false;
        if(s2.size()<s1.size())return ans;

        for(int i = 0; i < s1.size(); i++){
            count[(int)s1[i]-97]++;
        }

        for(int i = 0; i < s1.size(); i++){
            count[(int)s2[i]-97]--;
        }
        
        ans = (ans || allZeros(count));

        int fp = 0, lp = s1.size();
        for(int i = 0; i < s2.size() - s1.size(); i++){
            count[(int)s2[fp]-97]++;
            count[(int)s2[lp]-97]--;
            ans = ans || allZeros(count);
            fp++;
            lp++;
        }

        return ans;



    }
};

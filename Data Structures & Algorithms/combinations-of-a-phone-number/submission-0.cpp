class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> l = {{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        vector<string> ans = {{""}};

        if(digits.size() == 0)return {};

        for(int i = 0; i < digits.size(); i++){
            int num = (int)digits[i] - 49;
            vector<string> e;
            for(auto j: ans){
                for(auto k: l[num]){
                    e.push_back(j+k);
                }
            }
            ans = e;
        }
        return ans;
    }
};

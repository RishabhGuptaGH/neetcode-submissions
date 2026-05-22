class Solution {
public:
    vector<string> f(int o, int c, int n){
        if((o==n)&&(c==n))return {{}};

        if((c>o) || (o>n))return {};

        // Open
        vector<string> ans1 = f(o+1,c,n);
        for(auto& i: ans1) i += ')';

        // Close
        vector<string> ans2 = f(o,c+1,n);
        for(auto& i: ans2) i += '(';

        ans1.insert(ans1.end(), ans2.begin(), ans2.end());

        return ans1;
    }
    vector<string> generateParenthesis(int n) {
        return f(0, 0, n);
    }
};
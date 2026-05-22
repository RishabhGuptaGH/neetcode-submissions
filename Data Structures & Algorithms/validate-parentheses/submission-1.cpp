class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        bool ans = true;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c=='(' || c=='{' || c=='[')s1.push(c);
            else{
                if(s1.empty() ||( c==')'&&s1.top() != '(') || (c=='}'&&s1.top() != '{') || (c==']'&&s1.top() != '[')){
                    ans = false;
                    break;
                }
                else s1.pop();
            }
        }
        if(s1.size()>0)ans = false;
        return ans;
    }
};

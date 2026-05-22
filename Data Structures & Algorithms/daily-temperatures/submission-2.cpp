class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s1;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            int ct = temperatures[i];

            while(!s1.empty() && s1.top().first < ct){
                ans[s1.top().second] = i-s1.top().second;
                s1.pop();
            }
            s1.push({ct,i});
        }
        return ans;
    }
};

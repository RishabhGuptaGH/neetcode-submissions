class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,-1);

        int maxV = -1;
        for(int i = n-1; i>= 0; i--){
            if(temperatures[i] >= maxV){
                maxV = temperatures[i];
                ans[i] = 0;
                continue;
            }
            int idx = 1;
            while(true){
                if(temperatures[idx+i] > temperatures[i]){
                    ans[i] = idx;
                    break;
                }
                idx += ans[i+idx];
            } 
        }
        return ans;
    }
};

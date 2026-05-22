class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long p = 1;
        int zero = 0;

        for(auto i: nums){
            if(i==0)zero++;
            else p *= i;
        }
        vector<int> ans;

        for(auto i: nums){
            if(zero>=2)ans.push_back(0);
            else{
                if(i == 0)ans.push_back(p);
                else ans.push_back(p/i * (1-zero));
            }
        }

        return ans;
    }
};

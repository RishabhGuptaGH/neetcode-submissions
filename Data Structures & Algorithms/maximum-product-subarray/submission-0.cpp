class Solution {
public:

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        
        int p,n;
        if(nums[0] > 0){
            p = nums[0];
            n = 0;
        }
        else if(nums[0] < 0){
            p = 0;
            n = nums[0];
        }
        else{
            p = 0;
            n = 0;
        }

        int ans = p;
    
        for(int i = 1; i < nums.size(); i++){
            int newP = max({0, nums[i], nums[i]*p, nums[i]*n});
            int newN = min({0, nums[i], nums[i]*p, nums[i]*n});

            p = newP;
            n = newN;
            ans = max(ans, p);
        }
        return ans;
    }
};
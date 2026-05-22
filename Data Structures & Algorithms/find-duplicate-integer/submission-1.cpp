class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <nums.size(); i++){
            int  n = abs(nums[i]);
            nums[n-1] *= -1;
            if(nums[n-1]>0)ans = n;
        }
        return ans;
    }
};

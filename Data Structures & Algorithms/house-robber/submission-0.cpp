class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)return nums[0];

        vector<int> v1(n, -1);
        v1[0] = nums[0];
        v1[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            v1[i] = max(v1[i-2]+nums[i], v1[i-1]);
        }

        return v1[n-1];
    }
};
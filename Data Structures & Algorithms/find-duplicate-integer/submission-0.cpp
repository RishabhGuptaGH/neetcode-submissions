class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i])] > 0)nums[abs(nums[i])]*=-1;
            else return abs(nums[i]);
        }

        return 1;
    }
};

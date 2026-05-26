class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(auto& i: nums)i+=1;

        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i])-1 != nums.size())nums[abs(nums[i])-1] *= -1;
        }
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++)if(nums[i]>0)ans = i;
        return ans;
    }

};

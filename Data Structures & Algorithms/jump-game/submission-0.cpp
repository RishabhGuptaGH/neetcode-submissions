class Solution {
public:
    bool canJump(vector<int>& nums) {
        int validUpto = 0;
        bool ans = true;
        for(int i = 0; i < nums.size(); i++){
            if(validUpto < i){
                ans = false;
                break;
            }
            if(i+nums[i]>validUpto)validUpto = i+nums[i];
        }
        return ans;
    }
};

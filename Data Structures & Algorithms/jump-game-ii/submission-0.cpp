class Solution {
public:
    int jump(vector<int>& nums) {
        int idx = 0;
        int jumps = 0;
        int  n = nums.size();
        if(n == 1)return 0;

        while(idx < nums.size()){
            jumps++;
            if(idx+nums[idx] >= n-1)break;
            int longestIdx = 0;
            int longestDist = 0;
            for(int i = idx+1; i <= min(n-1,idx+nums[idx]); i++){
                if(nums[i]+i>longestDist){
                    longestIdx = i;
                    longestDist = nums[i]+i;
                }
            }
            idx = longestIdx;
        }
        return jumps;
    }
};

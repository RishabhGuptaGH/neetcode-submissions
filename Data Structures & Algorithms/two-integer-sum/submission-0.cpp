class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        int i1, i2;
        for(int i = 0; i < nums.size(); i++){
            if(m1.find(target-nums[i]) != m1.end()){
                i1 = i;
                i2 = m1[target-nums[i]];
                break; 
            }
            m1[nums[i]] = i;
        }
        return {min(i1,i2),max(i1,i2)};
    }
};
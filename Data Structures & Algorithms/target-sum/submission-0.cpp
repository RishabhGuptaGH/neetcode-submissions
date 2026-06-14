class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> m1;
        m1[nums[0]]=1;
        if(m1.find(nums[0]*(-1)) != m1.end())m1[nums[0]*(-1)]++;
        else m1[nums[0]*(-1)] = 1;

        for(int i = 1; i < nums.size(); i++){
            map<int,int> m2;
            for(auto j: m1){
                if(m2.find(j.first+nums[i]) == m2.end())m2[j.first+nums[i]] = j.second;
                else m2[j.first+nums[i]] += j.second;

                if(m2.find(j.first-nums[i]) == m2.end())m2[j.first-nums[i]] = j.second;
                else m2[j.first-nums[i]] += j.second;

            }
            m1 = m2;
        }

        if(m1.find(target) == m1.end())return 0;
        return m1[target];
    }
};
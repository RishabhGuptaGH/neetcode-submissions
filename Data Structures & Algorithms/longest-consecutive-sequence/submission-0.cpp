class Solution {
public:

    int num(int n, map<int,int>& m1){
        if(m1.find(n) == m1.end())return 0;
        if(m1[n] != 0)return m1[n];

        else return m1[n] = 1 + num(n+1, m1);
    }

    int longestConsecutive(vector<int>& nums) {
        map<int,int> m1;
        for(int i = 0; i < nums.size(); i++)m1[nums[i]] = 0;

        int ans = 0;
        for(auto i: nums)ans = max(ans, num(i, m1));

        return ans;
    }
};

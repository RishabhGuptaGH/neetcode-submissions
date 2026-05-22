class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m1;

        bool ans = false;
        for(auto i: nums){
            if(m1.find(i) == m1.end())m1[i]=1;
            else {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
vector<vector<int>> f(vector<int>& v1, int idx){
    if(idx == v1.size())return {{}};

    vector<vector<int>> ans = {};

    // Accept
    vector<vector<int>> t1 = f(v1, idx+1);
    for(auto& i: t1)i.push_back(v1[idx]);
    for(auto i: t1)ans.push_back(i);

    // Reject
    int curr = v1[idx];

    while(idx < v1.size() && v1[idx] == curr)idx++;
    vector<vector<int>> t2 = f(v1, idx);
    for(auto i: t2)ans.push_back(i);

    return ans;
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return f(nums, 0);
    }
};

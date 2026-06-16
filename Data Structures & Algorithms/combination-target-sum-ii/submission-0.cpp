vector<vector<int>> f(vector<int>& v1, int target, int idx){
    if(target == 0)return {{}};
    if(idx == v1.size())return {};

    vector<vector<int>> ans = {};

    // Acccept
    if(target>=v1[idx]){
        vector<vector<int>> t1 = f(v1, target-v1[idx], idx+1);
        for(auto& i: t1)i.push_back(v1[idx]);
        for(auto i: t1)ans.push_back(i);
    }

    // Reject
    int curr = v1[idx];
    while(idx < v1.size() && v1[idx] == curr){
        idx++;
    }
    vector<vector<int>> t2 = f(v1, target, idx);
    for(auto i: t2)ans.push_back(i);

    return ans;
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return f(candidates, target, 0);
    }
};
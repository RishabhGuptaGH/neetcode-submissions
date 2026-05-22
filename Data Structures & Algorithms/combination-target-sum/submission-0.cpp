class Solution {
    vector<vector<bool>> visited;
    vector<vector<vector<vector<int>>>> memo;

public:
    vector<vector<int>> f(int amount, int idx, vector<int>& cand) {
        if (amount == 0) {
            return {{}};
        }

        if (idx == cand.size()) {
            return {};
        }
        if (visited[amount][idx]) {
            return memo[amount][idx];
        }

        vector<vector<int>> ans1, ans2;

        // Accept
        if (amount >= cand[idx]) {
            ans1 = f(amount - cand[idx], idx, cand);
            for (auto& i : ans1) i.push_back(cand[idx]);
        }

        // Reject
        ans2 = f(amount, idx + 1, cand);

        ans1.insert(ans1.end(), ans2.begin(), ans2.end());
        
        // 2. Update the cache: Mark as visited and store the result
        visited[amount][idx] = true;
        memo[amount][idx] = ans1;
        
        return ans1;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
                visited.assign(target + 1, vector<bool>(n, false));
        memo.resize(target + 1, vector<vector<vector<int>>>(n));
        
        return f(target, 0, candidates);
    }
};
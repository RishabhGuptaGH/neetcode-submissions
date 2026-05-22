class Solution {
public:

    int f(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())return 0;

        if(dp[x][y] != -1)return dp[x][y];
        
        vector<int> ans = {1};

        // Up
        if(x-1 >= 0 && matrix[x-1][y] < matrix[x][y])ans.push_back(f(x-1,y,matrix, dp)+1);

        // Left
        if(y-1 >= 0 && matrix[x][y-1] < matrix[x][y])ans.push_back(f(x,y-1,matrix, dp)+1);

        // Down
        if(x+1 < matrix.size() && matrix[x+1][y] < matrix[x][y])ans.push_back(f(x+1,y,matrix, dp)+1);

        // Right
        if(y+1 < matrix[0].size() && matrix[x][y+1] < matrix[x][y])ans.push_back(f(x,y+1,matrix, dp)+1);

        sort(ans.begin(), ans.end());
        
        return dp[x][y] = ans[ans.size()-1];
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp;

        for(int i = 0; i < m; i++)dp.push_back(vector<int>(n, -1));

        int ans = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, f(i,j,matrix, dp));
            }
            cout << endl;
        }
        return ans;
    }
};
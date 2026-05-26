void f(int x, int y, vector<vector<int>>& heights, vector<vector<int>>& dp){
    if(dp[x][y]==1)return;

    int m = heights.size();
    int n = heights[0].size();

    if(x>=m || x<0 || y>=n || y<0)return;

    dp[x][y]=1;

    if(x-1>=0 && heights[x-1][y]>=heights[x][y])f(x-1,y,heights,dp);
    if(x+1<m && heights[x+1][y]>=heights[x][y])f(x+1,y,heights,dp);
    if(y+1<n && heights[x][y+1]>=heights[x][y])f(x,y+1,heights,dp);
    if(y-1>=0 && heights[x][y-1]>=heights[x][y])f(x,y-1,heights,dp);
}


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dp1, dp2;
        for(int i = 0; i < m; i++){
            dp1.push_back(vector<int>(n, -1));
            dp2.push_back(vector<int>(n, -1));
        }

        for(int i = 0; i < m; i++)f(i,0,heights,dp1);
        for(int i = 0; i < n; i++)f(0,i,heights,dp1);
        
        for(int i = 0; i < m; i++)f(i,n-1,heights,dp2);
        for(int i = 0; i < n; i++)f(m-1,i,heights,dp2);

        vector<vector<int>> ans = {};
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(dp1[x][y]==1&&dp2[x][y]==1)ans.push_back({x,y});
            }
        }
        return ans;
    }
};

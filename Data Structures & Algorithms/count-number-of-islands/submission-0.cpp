class Solution {
public:

    void f(int x, int y, vector<vector<bool>>& dp, vector<vector<char>>& grid){
        if((x<0)||(x>=grid.size())||(y<0)||(y>=grid[0].size())||(grid[x][y] == '0')||(dp[x][y]))return;

        dp[x][y] = true;

        f(x+1,y,dp,grid);
        f(x-1,y,dp,grid);
        f(x,y+1,dp,grid);
        f(x,y-1,dp,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> dp;
        for(int i = 0; i < grid.size(); i++){
            vector<bool> temp;
            for(int j = 0; j < grid[0].size(); j++){
                temp.push_back(false);
            }
            dp.push_back(temp);
        }

        int islands = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '0')continue;
                if(dp[i][j] == true)continue;

                f(i,j,dp,grid);

                islands++;
            }
        }
        return islands;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> p1;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        p1.push({grid[0][0],{0,0}});

        while(!p1.empty()){
            int val = p1.top().first;
            int x = p1.top().second.first;
            int y = p1.top().second.second;

            p1.pop();

            if(x<0 || y<0 ||x>=grid.size() || y>=grid[0].size() ||dp[x][y]!=-1){
                continue;
            }

            dp[x][y] = max(val, grid[x][y]);

            p1.push({dp[x][y], {x+1, y}});
            p1.push({dp[x][y], {x-1, y}});
            p1.push({dp[x][y], {x, y+1}});
            p1.push({dp[x][y], {x, y-1}});
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

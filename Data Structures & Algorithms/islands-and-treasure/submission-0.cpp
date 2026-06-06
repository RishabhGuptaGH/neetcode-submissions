class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q1;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==0)q1.push({i,j});
            }
        }

        while(!q1.empty()){
            pair<int,int> t = q1.front();
            q1.pop();

            int x = t.first;
            int y = t.second;

            if(x+1<grid.size() && grid[x+1][y]==INT32_MAX){
                grid[x+1][y]=grid[x][y]+1;
                q1.push({x+1,y});
            }
            if(x-1>=0 && grid[x-1][y]==INT32_MAX){
                grid[x-1][y]=grid[x][y]+1;
                q1.push({x-1,y});
            }
            if(y+1<grid[0].size() && grid[x][y+1]==INT32_MAX){
                grid[x][y+1]=grid[x][y]+1;
                q1.push({x,y+1});
            }
            if(y-1>=0 && grid[x][y-1]==INT32_MAX){
                grid[x][y-1]=grid[x][y]+1;
                q1.push({x,y-1});
            }
        }
    }
};

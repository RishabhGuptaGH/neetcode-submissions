void f(int x, int y, vector<vector<bool>>& v, vector<vector<char>>& g){
    if(x<0 || y<0 || x>=v.size() || y>=v[0].size() || g[x][y]!='1')return;
    if(v[x][y])return;

    v[x][y] = true;

    f(x+1,y,v,g);
    f(x-1,y,v,g);
    f(x,y+1,v,g);
    f(x,y-1,v,g);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> v;
        for(int i = 0; i < grid.size(); i++)v.push_back(vector<bool>(grid[0].size(), false));

        int c = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]=='1'&& v[i][j]==false){
                    f(i,j,v,grid);
                    c++;
                }
            }
        }
        return c;
    }
};

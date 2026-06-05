int f(int x, int y, vector<vector<bool>>& v, vector<vector<int>>& g){
    if(x<0 || y<0 || x>=v.size() || y>=v[0].size() || g[x][y]==0 || v[x][y])return 0;

    v[x][y] = true;
    return 1 + f(x+1,y,v,g) + f(x-1,y,v,g) + f(x,y-1,v,g) + f(x,y+1,v,g);
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> v;
        for(int i = 0; i < grid.size(); i++)v.push_back(vector<bool>(grid[0].size(), false));

        int m = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int n = 0;
                if(grid[i][j]==1&&v[i][j]==false)n = f(i,j,v,grid);
                m = max(m,n);
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
        return m;
    }
};

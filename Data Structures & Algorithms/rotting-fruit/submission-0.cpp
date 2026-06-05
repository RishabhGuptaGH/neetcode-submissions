class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q1;
        vector<vector<bool>> v;

        for(int i = 0; i < grid.size(); i++)v.push_back(vector<bool>(grid[0].size(), false));
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==2){
                    q1.push({i,j});
                    v[i][j] = true;
                }
                if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh == 0)return 0;

        int a = 0;
        while(true){
            a++;
            queue<pair<int,int>> q2;
            while(!q1.empty()){
                pair<int,int> p = q1.front();
                q1.pop();
                int i = p.first;
                int j = p.second;

                if(!(i+1<0 || j<0 || i+1>=grid.size() || j>=grid[0].size() || grid[i+1][j]!=1 || v[i+1][j])){
                    q2.push({i+1,j});
                    v[i+1][j]=true;
                    fresh--;
                }
                if(!(i-1<0 || j<0 || i-1>=grid.size() || j>=grid[0].size() || grid[i-1][j]!=1 || v[i-1][j])){
                    q2.push({i-1,j});
                    v[i-1][j]=true;
                    fresh--;
                }
                if(!(i<0 || j+1<0 || i>=grid.size() || j+1>=grid[0].size() || grid[i][j+1]!=1 || v[i][j+1])){
                    q2.push({i,j+1});
                    v[i][j+1]=true;
                    fresh--;
                }
                if(!(i<0 || j-1<0 || i>=grid.size() || j-1>=grid[0].size() || grid[i][j-1]!=1 || v[i][j-1])){
                    q2.push({i,j-1});
                    v[i][j-1]=true;
                    fresh--;
                }
            }
            q1 = q2;
            if(q1.size()==0 || fresh == 0)break;
        }
        if(fresh == 0)return a;
        else return -1;
    }
};

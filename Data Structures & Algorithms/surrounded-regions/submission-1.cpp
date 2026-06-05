bool f(int x, int y, vector<vector<bool>>& v, vector<vector<char>>& gr){
    if(x<0 || y<0 || x>=gr.size() || y>=gr[0].size())return true;
    if(gr[x][y]=='X' || v[x][y] == true)return false;

    v[x][y] = true;
    bool a = f(x+1,y,v,gr);
    bool b = f(x-1,y,v,gr);
    bool c = f(x,y+1,v,gr);
    bool d = f(x,y-1,v,gr);
    return a||b||c||d;
    
}

void g(int x, int y, vector<vector<bool>>& v, vector<vector<char>>& gr){
    if(x<0 || y<0 || x>=gr.size() || y>=gr[0].size() || gr[x][y]=='X')return;
    gr[x][y] = 'X';
    g(x+1,y,v,gr);
    g(x-1,y,v,gr);
    g(x,y+1,v,gr);
    g(x,y-1,v,gr);
}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> v;
        for(int i = 0; i < board.size(); i++)v.push_back(vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                bool ans = true;
                if(v[i][j]==false && board[i][j]=='O'){
                    ans = f(i,j,v,board);
                }
                if(!ans)g(i,j,v,board);

            }
        }
    }
};

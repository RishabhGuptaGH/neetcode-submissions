class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans = {};
        
        bool h = true, v = false;
        int dir = 1;
        int hs = 0, he = matrix[0].size()-1, vs = 1, ve = matrix.size()-1;

        int x = 0; int y = 0;
        while(ans.size() != matrix.size()*matrix[0].size()){
            if(h){
                if(y>he || y<hs){
                    if(y>he)he--;
                    if(y<hs)hs++;
                    y -= dir;
                    x += dir;
                    h = false;
                    v = true;
                }
                else{
                    ans.push_back(matrix[x][y]);
                    cout << matrix[x][y];
                    y+= dir;
                }
            }
            else{
                if(x>ve || x < vs){
                    if(x>ve)ve--;
                    if(x<vs)vs++;
                    x -= dir;
                    y -= dir;
                    dir = (-1)*dir;
                    h = true;
                    v = false;
                }
                else{
                    ans.push_back(matrix[x][y]);
                    cout << matrix[x][y];
                    x+= dir;
                }
            }
        }
        return ans;
    }
};

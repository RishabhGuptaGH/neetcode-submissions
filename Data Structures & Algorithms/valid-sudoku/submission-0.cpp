class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool c1 = true, c2 = true, c3 = true;
        for(int i = 0; i < 9; i++){
            unordered_map<char, bool> m1,m2;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(m1.find(board[i][j]) == m1.end())m1[board[i][j]] = true;
                    else c1 = false;
                }
                if(board[j][i] != '.'){
                    if(m2.find(board[j][i]) == m2.end())m2[board[j][i]] = true;
                    else c2 = false;
                }
            }
        }

        for(int x = 0; x < 9; x+=3){
            for(int y = 0; y < 9; y+= 3){
                unordered_map<char, bool> m1;
                for(int i = 0+x; i < 3+x; i++){
                    for(int j = 0+y; j < 3+y; j++){
                        if(board[i][j] != '.'){
                            if(m1.find(board[i][j]) == m1.end())m1[board[i][j]] = true;
                            else c3 = false;
                        }
                    }
                }
            }
        }
        cout << c1<<c2<<(bool)c3;
        if(c1 && c2 && c3)return true;
        else return false;
    }
};
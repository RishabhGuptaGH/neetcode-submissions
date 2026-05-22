class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int iterLen = n;
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < iterLen-1; j++){
                int v1 = matrix[i][i+j];
                int v2 = matrix[i+j][n-i-1];
                int v3 = matrix[n-i-1][n-i-j-1];
                int v4 = matrix[n-i-j-1][i];

                matrix[i][i+j] = v4;
                matrix[i+j][n-i-1] = v1;
                matrix[n-i-1][n-i-j-1] = v2;
                matrix[n-i-j-1][i] = v3;
            }
            iterLen -= 2;
        }
    }
};
class Solution {
public:
    int f(int n, vector<int>& v1){
        if(v1[n] != -1)return v1[n];

        return v1[n] = f(n-1,v1)+f(n-2,v1);
    }

    int climbStairs(int n) {
        
        if(n == 1)return 1;
        if(n == 2)return 2;

        vector<int> v1(n+1, -1);
        v1[1] = 1;
        v1[2] = 2;

        return f(n, v1);
    }
};
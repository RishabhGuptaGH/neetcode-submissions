class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);

        if(n==0)return {0};

        int p = 0;
        int e = 1;
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 2; i <= n; i++){
            if(p>e){
                e = e*2 + 1;
                p = 0;
            }
            ans[i] = ans[p]+1;
            p++;
        }
        return ans;
    }
};

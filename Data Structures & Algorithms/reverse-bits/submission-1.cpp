int f(uint32_t n){
    int ans = 0;
    int l = 0;
    while(n>0){
        ans*= 2;
        if(n%2==1)ans++;
        n=n/2;
        l++;
    }
    cout << l << endl;
    for(int i = 0; i < 32-l; i++)ans*=2;
    return ans;
}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return f(n);
    }
};

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x<0)sign = -1;

        long long int temp = abs((long long int)x);
        long long int num = 0;

        while(true){
            num += x % 10;
            x = x/10;

            if(x != 0){
                num *= 10;
                continue;
            }
            break;
        }
        num *= sign;

        if(num != (int)num)return 0;
        else return num*(sign);
    }
};
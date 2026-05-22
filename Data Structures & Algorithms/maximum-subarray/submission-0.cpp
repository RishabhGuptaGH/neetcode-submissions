class Solution {
public:
    int f(int start, int end, vector<int>& v1){
        if(start == end)return v1[start];

        int mid = (start+end)/2;

        int leftSum = f(start,mid,v1);
        int rightSum = f(mid+1,end,v1);

        //CommonSum
        int sum = 0;
        int maxSum = INT32_MIN;
        int maxSum2 = INT32_MIN;
        for(int i = mid; i>= 0; i--){
            sum += v1[i];
            maxSum = max(maxSum,sum);
        }
        sum = 0;
        for(int i = mid+1; i <= end; i++){
            sum += v1[i];
            maxSum2 = max(maxSum2,sum);           
        }

        return max(max(leftSum, rightSum),maxSum+maxSum2);
    }

    int maxSubArray(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
        
    }
};
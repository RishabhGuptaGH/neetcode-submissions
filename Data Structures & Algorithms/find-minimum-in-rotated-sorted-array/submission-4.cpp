class Solution {
public:
    
    int f(int low, int high, vector<int>& v1){

        if(low == high)return v1[low];

        int mid = (low+high)/2;

        if(v1[mid] > v1[high])return f(mid+1, high, v1);
        else return f(low, mid, v1);
    }


    int bs(int low, int high, int target, vector<int>& v1){
        int mid = (low+high)/2;

        if(low > high)return -1;

        if(target == v1[mid])return mid;

        else if(target > v1[mid])return bs(mid+1, high, target, v1);
        
        else return bs(low, mid-1, target, v1);
    }

    int findMin(vector<int> &nums) {
        if(nums[0] < nums[nums.size()-1])return nums[0];
        return f(0, nums.size()-1, nums);
    }
};

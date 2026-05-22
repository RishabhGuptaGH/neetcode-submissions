class Solution {
public:

    bool bs(int low, int high, int target,vector<int>& v1){
        if(low > high)return false;

        int mid = (low+high)/2;

        if(v1[mid] == target)return true;

        if(v1[mid] > target)return bs(low, mid-1, target, v1);
        else return bs(mid+1, high, target, v1);
    }

    int f(int low, int high, int target, vector<int>& v1){

        int mid = (low+high)/2;
        if(v1[mid] == target)return mid;

        if(low >= high)return low;

        if(v1[mid] > target)return f(low, mid-1, target, v1);
        else return f(mid+1, high, target, v1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        int count = 0;
        for(auto i: matrix){
            temp.push_back(i[0]);
            count++;
        }

        int ans = f(0,--count,target,temp);
        if(target < matrix[ans][0])ans--;
        if(ans < 0)return false;
        return bs(0,matrix[0].size()-1,target,matrix[ans]);
    }
};
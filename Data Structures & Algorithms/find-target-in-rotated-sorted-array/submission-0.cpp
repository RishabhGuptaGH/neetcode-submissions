class Solution {
public:

    int f(int low, int high, int target, vector<int>& v1){

        int mid = (low+high)/2;
        if(v1[mid] == target)return mid;

        //Base Case
        if(low >= high)return -1;

        //Sorted Second-Half
        if(v1[mid] < v1[high]){
            if((v1[mid]<target)&&(target<=v1[high]))return f(mid+1,high,target,v1);
            else return f(low, mid, target, v1);
        }

        //Sorted First-Half
        else{
            if((v1[low] <= target)&&(target <= v1[mid]))return f(low, mid,target,v1);
            else return f(mid+1,high,target,v1);
        }
                
    }

    int search(vector<int>& nums, int target) {
        return f(0,nums.size()-1,target,nums);
    }
};
int f(int s, int e, vector<int>& v1){
    if(s==e)return v1[s];

    int mid = (s+e)/2;

    if(v1[e]>=v1[mid]){
        return f(s,mid,v1);
    }
    else return f(mid+1,e,v1);
}


class Solution {
public:
    int findMin(vector<int> &nums) {
        return f(0, nums.size()-1, nums);
    }
};

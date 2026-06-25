class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p1;

        for(auto i: nums)p1.push(i);
        for(int i = 0; i < k-1; i++){
            p1.pop();
        }
        return p1.top();
    }
};
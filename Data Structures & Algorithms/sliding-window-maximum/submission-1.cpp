class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> p1;
        unordered_map<int,int> m1;
        vector<int> ans;

        for(int i = 0; i < k; i++){
            p1.push(nums[i]);
        }

        ans.push_back(p1.top());

        for(int i = 0; i < nums.size()-k; i++){
            if(m1.find(nums[i]) == m1.end())m1[nums[i]] = 0;
            m1[nums[i]]++;

            p1.push(nums[i+k]);

            while(m1.find(p1.top()) != m1.end() && m1[p1.top()] > 0){
                m1[p1.top()]--;
                p1.pop();
            }
            ans.push_back(p1.top());
        }
        return ans;
    }
};
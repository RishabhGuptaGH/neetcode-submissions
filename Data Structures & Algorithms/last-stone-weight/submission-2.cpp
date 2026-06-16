class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int, vector<int>> p1;

        for(auto i: stones)p1.push(i);

        int ans;
        while(!p1.empty()){
            int a = p1.top();
            p1.pop();
            if(p1.empty()){
                ans = a;
                break;
            }
            int b = p1.top();
            p1.pop();
            p1.push(abs(a-b));
        }
        return ans;
    }
};

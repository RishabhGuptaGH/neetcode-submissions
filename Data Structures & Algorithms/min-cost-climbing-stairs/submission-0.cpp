class Solution {
public:
    int f(vector<int>& v1, int idx, vector<int>& cost){
        if(v1[idx] != -1)return v1[idx];

        return v1[idx] = min(f(v1,idx-1, cost), f(v1,idx-2, cost))+cost[idx];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> v1(cost.size(),-1);


        v1[0] = cost[0];
        v1[1] = cost[1];

        return f(v1, cost.size()-1, cost);
    }
};
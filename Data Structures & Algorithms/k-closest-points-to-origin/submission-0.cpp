double d(int x, int y){
    return pow(pow(x,2)+pow(y,2),(double)1/(double)2);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> p1;

        vector<vector<int>> ans = {};

        for(auto i: points){
            p1.push({d(i[0], i[1]),{i[0], i[1]}});
        }

        while(k!=0){
            ans.push_back({p1.top().second.first, p1.top().second.second});
            p1.pop();
            k--;
        }
        return ans;
    }
};

int djs(int n, vector<vector<vector<int>>>& ad){
    vector<int> d(ad.size(), INT32_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p1;
    p1.push({0,n});

    while(!p1.empty()){
        pair<int,int> e = p1.top();
        p1.pop();

        if(e.first >= d[e.second])continue;

        d[e.second] = e.first;

        for(auto i: ad[e.second]){
            p1.push({e.first+i[0], i[1]});
        }
    }
    int ans = 0;
    for(auto i: d){
        ans = max(ans, i);
        cout << i << " ";
    }
    return ans;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> ad(n);

        for(auto i: times){
            int source = i[0] - 1;
            int target = i[1] - 1; 
            int weight = i[2];     
            
            ad[source].push_back({weight, target}); 
        }
        int ans = djs(k-1, ad);

        if(ans == INT32_MAX)ans = -1;

        return ans;
    }
};
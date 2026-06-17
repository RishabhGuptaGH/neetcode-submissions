int f(int n, vector<vector<vector<int>>>& ad, int k, int dst){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p1;
    vector<int> d(ad.size(), INT32_MAX);
    vector<int> c(ad.size(), 10000000);

    p1.push({0,{n, 0}});

    while(!p1.empty()){
        pair<int, pair<int,int>> t = p1.top();
        p1.pop();

        if(t.second.second > k)continue;

        if(t.first >= d[t.second.first] && t.second.second > c[t.second.first])continue;

        d[t.second.first] = min(d[t.second.first], t.first);
        c[t.second.first] = min(c[t.second.first], t.second.second);

        for(auto i: ad[t.second.first]){
            p1.push({t.first + i[0], {i[1], t.second.second+1}});
        }
    }
    return d[dst];
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> ad(n);

        for(auto i: flights){
            int source = i[0];
            int target = i[1]; 
            int weight = i[2];     
            
            ad[source].push_back({weight, target}); 
        }
        int ans = f(src, ad, k+1, dst);
        
        if(ans == INT32_MAX)ans = -1;

        return ans;
    }
};
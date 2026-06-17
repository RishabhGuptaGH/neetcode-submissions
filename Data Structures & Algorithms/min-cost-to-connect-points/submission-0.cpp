class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> ad;
        
        for(int i = 0; i < points.size(); i++){
            vector<int> t;
            for(int j = 0; j < points.size(); j++){
                t.push_back(abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
            }
            ad.push_back(t);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p1;

        p1.push({0,0});

        vector<bool> visited(n, false);

        int ans = 0;

        while(!p1.empty()){
            pair<int,int> a = p1.top();
            int dist = a.first;
            int node = a.second;
            
            p1.pop();

            if(visited[node])continue;
            visited[node] = true;
            ans += dist;

            for(int i = 0; i < ad[node].size(); i++){
                if(i == node)continue;
                p1.push({ad[node][i], i});
            }
        }
        return ans;
    }
};
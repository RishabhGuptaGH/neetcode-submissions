class Solution {
public:
    void dfs(int node, int& count, vector<vector<int>>& ad, vector<bool>& visited, int e1, int e2){
        visited[node-1] = true;
        count--;
        for(auto i: ad[node-1]){
            if(node==e1 && i==e2)continue;
            if(node==e2 && i==e1)continue;
            if(!visited[i-1])dfs(i, count, ad, visited, e1, e2);
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ad;
        for(int i = 0; i < edges.size(); i++)ad.push_back(vector<int>());
        for(auto i: edges){
            ad[i[0]-1].push_back(i[1]);
            ad[i[1]-1].push_back(i[0]);
        }

        for(int j = edges.size()-1; j>=0; j--){
            auto i = edges[j];
            int count = edges.size();
            vector<bool> visited(edges.size(), false);
            visited[i[0]-1] = true;
            dfs(i[0], count, ad, visited, i[0], i[1]);

            if(count == 0)return i;
        }

        return {};
    }
};
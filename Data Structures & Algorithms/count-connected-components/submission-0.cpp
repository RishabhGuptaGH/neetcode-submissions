void dfs(int n, unordered_map<int,vector<int>>& m1, vector<bool>& visited){
    if(visited[n])return;
    visited[n] = true;
    for(auto i: m1[n]){
        if(!visited[i])dfs(i, m1, visited);
    }
}

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<bool> visited(n, false);
        unordered_map<int,vector<int>> m1;
        for(int i = 0; i < n; i++)m1[i]={};

        for(auto i: edges){
            m1[i[0]].push_back(i[1]);
            m1[i[1]].push_back(i[0]);
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, m1, visited);
                c++;
            }
        }
        return c;
    }
};

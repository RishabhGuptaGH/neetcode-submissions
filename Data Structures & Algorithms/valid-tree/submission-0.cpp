void dfs(int n, unordered_map<int,vector<int>>& m1, vector<bool>& visited, int& c){
    if(visited[n])return;
    visited[n] = true;
    c++;
    for(auto i: m1[n]){
        if(!visited[i])dfs(i, m1, visited, c);
    }
}

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>=n || edges.size()<n-1)return false;

        vector<bool> visited(n, false);
        unordered_map<int,vector<int>> m1;
        for(int i = 0; i < n; i++)m1[i]={};

        for(auto i: edges){
            m1[i[0]].push_back(i[1]);
            m1[i[1]].push_back(i[0]);
        }

        int c = 0;
        dfs(0, m1, visited, c);

        return n==c;
    }
};

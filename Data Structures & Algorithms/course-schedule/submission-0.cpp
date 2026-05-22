class Solution {
public:

    bool f(int course, set<int>& visited, unordered_map<int,set<int>>& m1,vector<int>& dp){
        if(m1[course].size() == 0)return dp[course]=true;
        if(dp[course] == 1)return true;
        if(dp[course] == 0)return false;

        for(auto i: m1[course]){
            if(visited.find(i) != visited.end())return dp[course]= false;
            visited.insert(i);
            bool valid = f(i, visited, m1,dp);
            if(valid == false)return dp[course]= false;
            visited.erase(i);
        }
        return dp[course] = true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,set<int>> m1;
        vector<int> dp(numCourses,-1);

        for(int i = 0; i < numCourses; i++){
            set<int> v1;
            m1[i] = v1;
        }
        
        for(auto i: prerequisites){
            m1[i[0]].insert(i[1]);
        }

        bool v = true;

        for(auto i: m1){
            set<int> v1;
            v = v && f(i.first,v1,m1,dp);
        }
        return v;
    }
};

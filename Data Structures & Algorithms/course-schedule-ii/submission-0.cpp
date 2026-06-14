vector<int> f(int n, vector<vector<int>>& ad, vector<bool>& v, vector<bool>& c){
    if(v[n])return {-1};
    v[n] = true;

    vector<int> ans = {};
    for(auto i: ad[n]){
        vector<int> t;
        if(c[i]==false)t = f(i, ad, v, c);
        if(t.size()==1 && t[0]==-1)return {-1};
        for(auto j: t)ans.push_back(j);
    }
    ans.push_back(n);
    c[n] = true;
    return ans;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> v(numCourses, false);
        vector<bool> c(numCourses, false);

        vector<vector<int>> ad;
        for(int i = 0; i < numCourses; i++)ad.push_back(vector<int>());
        for(int i = 0; i < prerequisites.size(); i++)ad[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<int> ans = {};
        for(int i = 0; i < numCourses; i++){
            if(c[i]==false){
                vector<int> t = f(i, ad, v, c);
                if(t.size()==1 && t[0]==-1)return {};
                for(auto j: t)ans.push_back(j);
            }
        }
        return ans;
    }
};
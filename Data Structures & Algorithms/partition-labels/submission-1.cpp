class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int,int>> m1;
        vector<pair<int,int>> v1;
        vector<int> ans;
        
        for(int i = 0; i < s.size(); i++){
            if(m1.find(s[i]) == m1.end()){
                pair<int,int> p1 = {i,i};
                m1[s[i]] = p1;
            }
            else{
                m1[s[i]].second = i;
            }
        }

        for(auto i: m1)v1.push_back(i.second);
        sort(v1.begin(), v1.end());

        for(auto i: v1)cout << i.first << " " << i.second << "; ";
        int start = v1[0].first;
        int end   = v1[0].second;

        for(int i = 1; i < v1.size(); i++){
            if(v1[i].first > end){
                ans.push_back(end-start+1);
                start = v1[i].first;
                end = v1[i].second;
            }
            else{
                end = max(end,v1[i].second);
            }
        }
        ans.push_back(end-start+1);

        return ans;
    }
};

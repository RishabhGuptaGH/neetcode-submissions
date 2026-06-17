class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        int s = intervals[0][0];
        int e = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int ts = intervals[i][0];
            int te = intervals[i][1];

            if(ts > e){
                ans.push_back({s,e});
                s = ts;
                e = te;
            }
            else{
                e = max(e, te);
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};
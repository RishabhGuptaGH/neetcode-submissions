class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> arr = intervals;
        vector<vector<int>> ans;
        vector<int> temp = newInterval;

        int s = temp[0], e = temp[1];

        for(int i = 0; i < arr.size(); i++){
            // Left Collision
            if((arr[i][0] <= temp[0])&&(arr[i][1] >= temp[0])){
                s = min(s, arr[i][0]);
                e = max(e, arr[i][1]);
            }

            // Right Collision
            else if((arr[i][0] <= temp[1])&&(arr[i][1] >= temp[1])){
                s = min(s, arr[i][0]);
                e = max(e, arr[i][1]);
            }

            // Overlap
            else if((arr[i][0]>=temp[0])&&(arr[i][1] <= temp[1]))continue;

            else ans.push_back(arr[i]);
        }
        ans.push_back({s,e});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
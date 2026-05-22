class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        for(auto& i: intervals){
            int temp = i[0];
            i[0] = i[1];
            i[1] = temp;
        }

        sort(intervals.begin(), intervals.end());

        int epstein = 1;
        int end = intervals[0][0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] >= end){
                end = intervals[i][0];
                epstein++;
            }
        }
        return intervals.size() - epstein;
    }
};
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> v1;
        if(intervals.size() == 0)return true;
        for(int i = 0; i < intervals.size(); i++){
            pair<int,int> t = {intervals[i].start, intervals[i].end};
            v1.push_back(t);
        }
        sort(v1.begin(), v1.end());
        bool ans = true;
        for(int i = 0; i < intervals.size()-1; i++)if(v1[i].second > v1[i+1].first)ans = false;
        return ans;
    }
};

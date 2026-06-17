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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = 0;
        int m = 0;
        priority_queue<int, vector<int>, greater<int>> p1;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        for(int i = 0; i < intervals.size(); i++){
            while(!p1.empty() && p1.top() <= intervals[i].start){
                n--;
                p1.pop();
            }
            p1.push(intervals[i].end);
            n++;
            m = max(m, n);
        }
        return m;
    }
};

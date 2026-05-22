class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size(), -1), left(heights.size(), -1);

        // Strictly increasing in right
        stack<pair<int,int>> s1;
        for(int i = 0; i < heights.size(); i++){
            if(s1.empty() || s1.top().first <= heights[i]){
                s1.push({heights[i], i});
            }
            else{
                while(!s1.empty()&&s1.top().first>heights[i]){
                    right[s1.top().second] = i-s1.top().second-1;
                    s1.pop();
                }
                s1.push({heights[i], i});
            }
        }
        while(!s1.empty()){
            right[s1.top().second] = heights.size()-s1.top().second-1;
            s1.pop();
        }

        // Strictly Increasing in left
        for(int i = heights.size()-1; i >= 0; i--){
            if(s1.empty() || s1.top().first <= heights[i]){
                s1.push({heights[i], i});
            }
            else{
                while(!s1.empty()&&s1.top().first>heights[i]){
                    left[s1.top().second] = abs(i-s1.top().second)-1;
                    s1.pop();
                }
                s1.push({heights[i], i});
            }
        }
        while(!s1.empty()){
            left[s1.top().second] = s1.top().second;
            s1.pop();
        }

        int area = 0;

        for(int i = 0; i < heights.size(); i++){
            area = max(area, heights[i]*(left[i]+right[i]+1));
        }
        return area;
    }
};
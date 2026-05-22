class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(),-1);
        vector<int> right(heights.size(),heights.size());

        stack<pair<int,int>> s1;
        
        // Left
        int idx = heights.size()-1;
        s1.push({heights.size()-1, heights[heights.size()-1]});
        idx--;

        while(idx>=0){
            if(s1.empty()){
                s1.push({idx,heights[idx]});
                idx--;
                continue;
            }
            if(heights[idx] >= s1.top().second){
                s1.push({idx, heights[idx]});
                idx--;
                continue;
            }
            while(s1.top().second > heights[idx]){
                left[s1.top().first] = idx;
                s1.pop();
                if(s1.empty())break;
            }
        }
        while(!s1.empty())s1.pop();

        //Right
        idx =  1;
        s1.push({0, heights[0]});

        while(idx < heights.size()){
            if(s1.empty()){
                s1.push({idx,heights[idx]});
                idx++;
                continue;
            }
            if(heights[idx] >= s1.top().second){
                s1.push({idx, heights[idx]});
                idx++;
                continue;
            }
            while(s1.top().second > heights[idx]){
                right[s1.top().first] = idx;
                s1.pop();
                if(s1.empty())break;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int leftLen = i-left[i]-1;
            int rightLen = right[i]-i-1;
            maxArea = max(maxArea, heights[i]*(1+leftLen+rightLen));
        }
        return maxArea;
    }
};
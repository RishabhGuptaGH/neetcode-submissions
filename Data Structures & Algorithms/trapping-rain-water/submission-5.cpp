class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> bar;
        vector<int> heights = height;
        int gmax = 0;
        for(int i = 0; i < heights.size(); i++)gmax = max(gmax, heights[i]);

        vector<pair<int,int>> left, right;

        int lmax = 0, rmax = 0, junk = 0, l, r;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] > lmax){
                lmax = heights[i];
                left.push_back({heights[i], i});
            }
            else junk+=heights[i];
            if(lmax == gmax){
                l = i;
                break;
            }
        }
        for(int i = heights.size()-1; i >= 0; i--){
            if(heights[i] > rmax){
                rmax = heights[i];
                right.push_back({heights[i], i});
            }
            else junk+=heights[i];

            if(rmax == gmax){
                r = i;
                break;
            }
        }
        // for(auto i: right)cout << i.first << " " << i.second << "; ";

        int ans = 0;
        for(int i = 0; i < (int)left.size()-1; i++){
            ans += (left[i].first)*(left[i+1].second - left[i].second-1);
        }
        for(int i = 0; i < (int)right.size()-1; i++){
            ans += (right[i].first)*(abs(right[i+1].second - right[i].second)-1);
        }
        for(int i = l+1; i < r; i++)junk += heights[i];
        ans += (max(r-l-1, 0))*(gmax);
        // cout << r<<l;
        ans-=junk;
        return ans;
    }
};

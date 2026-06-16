class Solution {
public:
    int maxArea(vector<int>& height) {
        int g = 0;
        int n = height.size();

        for(int i = 0; i < n; i++){
            if(height[i]>g)g=height[i];
        }

        vector<int> l, r;

        int c = 0;
        for(int i = 0; i < n; i++){
            if(height[i]>c){
                l.push_back(i);
                c = height[i];
            }
            if(c==g)break;
        }
        
        c = 0;
        for(int i = n-1; i >= 0; i--){
            if(height[i]>c){
                r.push_back(i);
                c = height[i];
            }
            if(c==g)break;
        }

        int ans = 0;

        int li = 0, ri = 0;

        while(true){
            ans = max(ans, (r[ri]-l[li])*(min(height[l[li]], height[r[ri]])));

            if((li == l.size()-1) && (ri == r.size()-1))break;

            if(li == l.size()-1)ri++;

            else if(ri == r.size()-1)li++;

            else{
                if((r[ri+1]-l[li])*min(height[l[li]], height[r[ri+1]]) > (r[ri]-l[li+1])*min(height[l[li+1]], height[r[ri]]))ri++;
                else li++;
            }
        }

        return ans;
    }
};
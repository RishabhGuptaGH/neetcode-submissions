class Solution {
public:
    int maxArea(vector<int>& height) {
        long long g = 0;
        long long n = height.size();

        for(long long i = 0; i < n; i++){
            if(height[i]>g)g=height[i];
        }

        vector<long long> l, r;

        long long c = 0;
        for(long long i = 0; i < n; i++){
            if(height[i]>c){
                l.push_back(i);
                c = height[i];
            }
            if(c==g)break;
        }
        
        c = 0;
        for(long long i = n-1; i >= 0; i--){
            if(height[i]>c){
                r.push_back(i);
                c = height[i];
            }
            if(c==g)break;
        }

        long long ans = 0;

        long long li = 0, ri = 0;

        while(true){
            ans = max(ans, (r[ri]-l[li])*(min(height[l[li]], height[r[ri]])));

            if((li == l.size()-1) && (ri == r.size()-1))break;

            if(li == l.size()-1)ri++;

            else if(ri == r.size()-1)li++;

            else{
                if(height[r[ri]]<height[l[li]])ri++;
                else li++;
            }
        }

        return ans;
    }
};
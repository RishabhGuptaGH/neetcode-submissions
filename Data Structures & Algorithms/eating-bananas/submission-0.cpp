class Solution {
public:

    int f(int low, int high, vector<int>& v1, int h){
        if(low == high){
            return low;
        }

        int pace = (low+high)/2;
        int time = 0;

        for(int i = 0; i < v1.size(); i++){
            time += ceil((double)v1[i]/(double)pace);
        }

        if(time > h){
            return f(pace+1,high,v1,h);
        }
        else{
            return f(low,pace,v1,h);
        }

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = INT32_MIN;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > maxVal)maxVal = piles[i];
        }
        return f(1, maxVal,piles,h);
    }
};
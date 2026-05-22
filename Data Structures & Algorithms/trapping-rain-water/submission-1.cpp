class Solution {
public:
    int trap(vector<int>& height) {
        int maxV = 0;

        for(int i = 0; i < height.size(); i++){
            if(height[i] > maxV)maxV = height[i];
        }

        int fi1,fi2;

        //Start to End
        int localMax = height[0];
        int idx = 0;
        int uselessArea = 0;
        int water = 0;

        for(int i = 0; i < height.size(); i++){
            if(height[i] >= localMax){
                water += min(height[idx], height[i]) * (max(0,i-idx-1));
                water -= uselessArea;
                localMax = height[i];
                idx = i;
                uselessArea = 0;
            }
            else{
                uselessArea += height[i];
            }

            if(height[i] == maxV)break;
        }
        fi1 = idx;

        //End to Start
        localMax = height[height.size()-1];
        idx = height.size()-1;
        uselessArea = 0;

        for(int i = height.size()-1; i >= 0; i--){
            if(height[i] >= localMax){
                water += min(height[idx], height[i]) * (max(0,idx-i-1));
                water -= uselessArea;
                localMax = height[i];
                idx = i;
                uselessArea = 0;
            }
            else{
                uselessArea += height[i];
            }

            if(height[i] == maxV)break;
        }
        fi2 = idx;
        if(fi1 != fi2){
            uselessArea = 0;
            for(int i = fi1+1; i < fi2; i++){
                uselessArea += height[i];
            }

            water += height[fi1]*(fi2-fi1-1);
            water -= uselessArea;
        }
        return water;
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;
        int av = target[0], bv = target[1], cv = target[2];

        for(int i = 0; i < triplets.size(); i++){
            if((triplets[i][0] > av)||(triplets[i][1] > bv)||(triplets[i][2] > cv))continue;
            if(triplets[i][0] == av)a = true;
            if(triplets[i][1] == bv)b = true;
            if(triplets[i][2] == cv)c = true;
        }
        return a & b & c;
    }
};

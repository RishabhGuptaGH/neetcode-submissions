class Solution {
public:
    bool unique(vector<int>& v1, vector<int>& v2){
        if(v1.size() != v2.size())return false;
        for(int i = 0; i < v1.size(); i++)if(v1[i] != v2 [i])return false;
        return true;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {};

        for(int i = 0; i < (int)nums.size()-2; i++){
            int l = i+1, r = (int)nums.size()-1;
            int tar = (-1)*nums[i];
            while(l < r){
                if(nums[l]+nums[r]>tar)r--;
                else if(nums[l]+nums[r]<tar)l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    r--;
                } 
                    
            }
        }
        vector<vector<int>> f_ans;
        sort(ans.begin(), ans.end());

        if(ans.size()== 0)return {};
        int p = 0;
        for(int i = 1; i < ans.size(); i++){
            if(!unique(ans[p], ans[i])){
                f_ans.push_back(ans[p]);
                p = i;
            }
        }
        f_ans.push_back(ans[p]);
        return f_ans;
    }
};

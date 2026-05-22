class Solution {
public:
    vector<vector<int>> f(vector<int> arr){
        if(arr.size() == 0)return {{}};
        vector<vector<int>> fa;
        
        for(int i = 0; i < arr.size(); i++){
            vector<int> vd;
            for(int j = 0; j < arr.size(); j++)if(j != i)vd.push_back(arr[j]);
            vector<vector<int>> ans = f(vd);

            for(auto& j: ans)j.push_back(arr[i]);

            fa.insert(fa.end(), ans.begin(), ans.end());
        }

        return fa;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return f(nums);
    }
};
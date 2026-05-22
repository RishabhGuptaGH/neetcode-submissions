class Solution {
public:
    int select(vector<pair<int,int>>& v1, int s, int e, int k){
        if (s == e) return s;
        
        pair<int,int> pv = v1[s + (e-s)%k];
        int l = e;
        for(int i = s; i <= l; i++){
            if(v1[i].second >= pv.second){
                pair<int,int> t = v1[i];
                v1[i] = v1[l];
                v1[l] = t;
                l--;
                i--;
            }
        }
        for(int i = l+1; i <= e; i++){
            if(v1[i].first == pv.first){
                pair<int,int> t = v1[i];
                v1[i] = v1[l+1];
                v1[l+1] = t;
                break;
            }
        }
        l++;
        if(e-l+1 > k){
            return select(v1, l+1, e, k);
        }
        else if(e-l+1 == k){
            return l;
        }
        else return select(v1, s, l-1, k - (e-l+1));
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;

        for(int i = 0; i < nums.size(); i++){
            if(m1.find(nums[i]) == m1.end())    m1[nums[i]] = 1;
            else m1[nums[i]]++;
        }
        vector<pair<int,int>> m2;
        for(auto i: m1)m2.push_back(i);
        
        int l = select(m2, 0 , m2.size()-1, k);

        vector<int> ans;

        for(int i = l; i < m2.size(); i++)ans.push_back(m2[i].first);

        return ans;
    }
};

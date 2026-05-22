class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> del;
        for(int i = 0; i < gas.size(); i++)del.push_back(gas[i]-cost[i]);

        int sum   = 0;
        int start = 0;
        int ans = false;

        for(int i = 0; i < 2*gas.size(); i++){
            int idx = i % gas.size();
            sum += del[idx];

            if(i - start >= gas.size())break;

            if(sum < 0){

                if(i < gas.size()-1){
                    sum = 0;
                    start = i+1;
                }
                else{
                    start = -1;
                    break;
                }
            }
        }
        return start;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size()-1;

        int i1,i2;
        while(s<e){
            if(numbers[s]+numbers[e]>target)e--;
            else if(numbers[s]+numbers[e]<target)s++;
            else{
                i1 = s, i2 = e;
                break;
            }
        }
        return {i1+1,i2+1};
    }
};

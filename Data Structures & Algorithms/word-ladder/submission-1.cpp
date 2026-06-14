int diff(string& s1, string& s2){
    int c = 0;
    for(int i = 0; i < s1.size(); i++)if(s1[i]!=s2[i])c++;
    return c;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> m1;
        unordered_map<string, int> dp;

        for(int i = 0; i < wordList.size(); i++){
            m1[wordList[i]] = {};
            dp[wordList[i]] = -1;
            for(int j = 0; j < wordList.size(); j++){
                if(i==j)continue;
                if(diff(wordList[i], wordList[j]) == 1){
                    m1[wordList[i]].push_back(wordList[j]);
                }
            }
        }

        dp[beginWord] = 1;
        m1[beginWord] = {};
        for(int i = 0; i < wordList.size(); i++){
            if(diff(beginWord, wordList[i]) == 1){
                m1[beginWord].push_back(wordList[i]);
            }
        }

        queue<string> q1;

        q1.push(beginWord);

        while(!q1.empty()){
            string t = q1.front();
            q1.pop();
            for(auto i: m1[t]){
                if(dp[i] == -1){
                    dp[i] = dp[t]+1;
                    q1.push(i);
                }
            }
        }

        for(auto i: m1){
            cout << i.first << ": ";
            for(auto j: i.second)cout << j << ", ";
            cout << endl;
        }
        return max(0, dp[endWord]);
    }
};
#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
    // O(n^3) time, O(n) space
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> word(wordDict.begin(), wordDict.end());
       vector<bool> dp(s.length() + 1);
       dp[0] = true;
       
       for(int i = 1; i <= s.length(); i++){
           for(int j = 0; j < i; j++){
               if (dp[j] && word.find(s.substr(j, i - j)) != word.end()){
                   dp[i] = true;
                   break;
               }
           }
       }
       return dp[s.length()];
    }

};

int main(){
    Solution s;
    vector<string> wordDict = {"leet", "code"};
    cout << s.wordBreak("leetcode", wordDict) << endl;
    return 0;
}
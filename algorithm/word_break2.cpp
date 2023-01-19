#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

class Solution {
public:
    // O(n^3) time, O(n^2) space
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.length() + 1, vector<int> {});
        set<string> word(wordDict.begin(), wordDict.end());
        dp[0].push_back(0);
        vector<string> ans;
        string words = "";

        for(int i = 1; i <= s.length(); i++){
            for(int j=0; j < i; j++){
                if (dp[j].size() > 0 && word.find(s.substr(j, i-j)) != word.end()){
                    dp[i].push_back(j);
                }
            }
        }

        sentence(dp, s.length(), words, ans, s);
        return ans;
    }

    int sentence(vector<vector<int>> &dp, int end, string words, vector<string> &ans, string s){
        if(end == 0) {
            ans.push_back(words.substr(1));
            return 0;
        }

        for(auto index: dp[end]){
            string new_words = " " + s.substr(index, end - index) + words;
            sentence(dp, index, new_words, ans, s);
        }

        return 0;
    }
};

int main(){
    Solution s;
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = s.wordBreak("catsanddog", wordDict);
    for(auto word: ans){
        cout << word << endl;
    }
    return 0;
}
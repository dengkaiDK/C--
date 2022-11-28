#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution{
public:
    map<char, string> phone{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans{};
        if (digits.empty()){
            return ans;
        }
        string path{};
        backtracking(digits, 0, path, ans);
        return ans;
    }

    void backtracking(string digits, int index, string path, vector<string>& ans){
        if (index == digits.size()){
            ans.push_back(path);
            return;
        }
        char digit = digits[index];
        string letters = phone[digit];
        for (int i = 0; i < letters.size(); i++){
            path.push_back(letters[i]);
            backtracking(digits, index + 1, path, ans);
            path.pop_back();
        }
    }
};


int main(){
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
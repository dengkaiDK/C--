#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    string ans;
    
    bool exist(vector<vector<char>>& board, string word) {
        ans = word;
        map<char, int> numbers;
        map<char, int> words;
        for(auto v: board)
            for(auto c: v)
                numbers[c] = numbers.find(c) != numbers.end() ? \
                numbers[c] + 1: 1;
        
        for(auto c: word)
            words[c] = words.find(c) != words.end() ? words[c] + 1: 1;

        for(auto it : words)
        {
            if(numbers.find(it.first) == numbers.end() || numbers[it.first] < it.second)
                return false;
        }

        for(auto i =0; i < board.size(); i++)
            for(auto j=0; j < board[i].size(); j++)
            {
                if (find(board, 0, i, j))
                    return true;
            }

        return false;
    }

    bool find(vector<vector<char>>& board, int index, int i, int j){
        if (index == ans.size()){
            return true;
        }
        if (i >= board.size() || i < 0) return false;
        if (j >= board[i].size() || j < 0) return false;
        if (board[i][j] != ans[index]) return false;
        

        board[i][j] = ' ';
        bool res;
        
        res = find(board, index+1, i+1, j) || find(board, index+1,
            i, j+1) || find(board, index+1, i-1, j) || find(board, index+1, i, j-1);

        board[i][j] = ans[index];
        return res;
    }
};


int main(){
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
    return 0;
}
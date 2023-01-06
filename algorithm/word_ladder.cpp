#include<iostream>
#include<map>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto s : wordList){
            int k = s.size();
            for(auto i = 0; i < k; i++){
                string intermediate = s.substr(0, i) + "*" + s.substr(i+1);
                table[intermediate].push_back(s);
            }
        }

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        queue<pair<string, int>> bfs;
        bfs.push(make_pair(beginWord, 1));
        int L = beginWord.size();
        

        while(!bfs.empty()){
            pair<string, int> it = bfs.front();
            bfs.pop();
            
           for(int i=0; i<L; i++){
               string intermediate = it.first.substr(0, i) + "*" + it.first.substr(i+1);
               if(table.find(intermediate) != table.end()){
                   for(string word: table[intermediate]){
                       if(word == endWord) return it.second + 1;
                       if(visit.find(word) == visit.end()){
                           visit.insert(word);
                           bfs.push(make_pair(word, it.second + 1));
                       }
                   }
                   table.erase(intermediate);
               }

           }
        }

        return 0;
    }

private:
    map<string, vector<string>> table;
    set<string> visit;
};

int main(){
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;
    return 0;

}
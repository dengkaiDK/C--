#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    map<pair<int, int>, string> pa;
    bool static comp(pair<pair<int, int>,string> a, pair<pair<int, int>, string> b){
        int la = a.first.second - a.first.first + 1;
        int lb = b.first.second - b.first.first + 1;
        return la < lb;
    }
    string longestPalindrome(string s) {
        int i;
        for(i =0; i<s.size(); i++){
            findPalindrome(s, i, i);
        }
        auto it = max_element(pa.begin(), pa.end(), comp);
        return it->second;
    }
    
    void findPalindrome(string s, int start, int end){
        if(pa.find(make_pair(start, end))!=pa.end())
            return;
        
        if(s[start] == s[end]){
            pa[make_pair(start, end)] = s.substr(start, end - start + 1);
        }
        else
            return ;
        
        if(start == end){
            if(start - 1>=0){
                findPalindrome(s, start - 1, start);
            }
            if(end + 1 < s.size())
                findPalindrome(s, end, end + 1);
        }
        
        if(start -1 >=0 && end+1 < s.size())
            findPalindrome(s, start-1, end+1);
        
        return ;    
    }
};

int main(){
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}
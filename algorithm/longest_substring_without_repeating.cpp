#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, bool> map;
        int max_len =0;
        int start = 0;
        int end = 0;
        while (start < s.size()){
            if (map.find(s[end])== map.end() && end < s.size()){
                map[s[end]] = true;
                end++;
            }
            else{
                map.erase(s[start]);
                start++;
            }
            max_len = max(max_len, end-start);
        }
        return max_len;
    }
};

int main(){
    string s = "akoqwe";
    Solution r;
    int result = r.lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
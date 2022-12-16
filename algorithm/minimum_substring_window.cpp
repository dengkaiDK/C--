#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        map<char, int> match;
        for(auto c : t){
            match[c] = match.find(c) != match.end() ? match[c] + 1 : 1;
        }

        map<char, int> look;
        bool found = false;
        bool update = false;
        int minimum = INT_MAX;
        pair<int, int> range;

        while (start < s.size() && match.find(s[start]) == match.end()) start++;
        if (start == s.size()) return "";
        look[s[start]] = 1;
        end = start + 1;

        
        found = false;
        if (match.size() == 1 && look[s[start]] == match[s[start]])
            found = true;
        if (found) {
            return string(1, s[start]);
        }
        

        while(end < s.size()){
           if (match.find(s[end]) != match.end()){
               if(!update)
                    look[s[end]] = look.find(s[end]) != look.end() ? look[s[end]] + 1: 1;
                // avoid too many duplicate chars
                if (look.size() < match.size()) {
                    end++;
                    continue;
                }
                found = true;
                for(auto it = match.begin(); it!=match.end(); it++){
                    if (look[it->first] < it->second)
                        {
                            found = false;
                            break;
                        }
                }

                if(found){
                    if (end - start + 1 < minimum){
                        minimum = end - start + 1;
                        range = make_pair(start , end);
                    }
                    
                    look[s[start]] -= 1;
                    start++;
                    while(match.find(s[start]) == match.end() || look[s[start]] > match[s[start]]){
                        if (look.find(s[start]) != look.end()) 
                            look[s[start]] -= 1;
                        start++;
                    } 
                    
                    update = true;
                }
                else {
                    end++;
                    update = false;
                }
            }
            else{
                end++;
            }
        }

        if(minimum == INT_MAX){
            return "";
        }
        string ans = "";
        for(start = range.first; start <= range.second; start++)
            ans.push_back(s[start]);
        
        return ans;
    }
};


int main(){
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout << s.minWindow(s1, s2) << endl;
    return 0;
}
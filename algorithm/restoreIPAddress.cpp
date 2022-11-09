#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<set>

using namespace std;

class Solution {
public:
    set<string> result;
    vector<string> restoreIpAddresses(string s) {
        int j;
        vector<string> ret;
        for(j=1; j < 4; j++)
            validIP(s, 0, j, 1);
        
        set<string>::iterator it;
        for(it = result.begin(); it != result.end(); it++)
            ret.push_back(*it);
        return ret;
    }
    
    void validIP(string s, int i, int len, int domain){
        if (domain == 4){
            if (i >= s.length() || stol(s.substr(i)) > 255 || (s[i] == '0' && i + 1 < s.length()))
                return ;
            result.insert(s);
            //last digit might have repeating numbers.
            //cout << s << endl;
        }
        else{
            assert(i < s.length());

            long val = stol(s.substr(i, len));
            char c = s[i];
            if (val > 255 || (c == '0' && len > 1))
                return ;

            string s0(s);
            s0.insert(i + len, 1, '.');
            i += len+1;

            for(int j=1; j <=3; j++){
                if (i + j <= s0.length())
                    validIP(s0, i, j, domain+1); // last digit might repeat
            }
                
        }
    }
};

int main(){
    Solution a;
    string s = "101023";
    // cout << s.substr(0, 1) << endl;
    // cout << stoi(s.substr(0, 2)) << endl;
    //s.insert(0, 1, '.'); // insert before index
    //cout << s << endl;
    vector<string> result = a.restoreIpAddresses(s);
    for(auto m: result)
    {
        cout << m << endl;
    }
    return 0;
}
#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    map<int, int> decode;
    int numDecodings(string s) {
        decode.clear();
        return Decoding(s, 0);
    }

    int Decoding(string s, int i){
        if (i == s.size()) return 1;
        if (decode.find(i) != decode.end()) return decode[i];

        char c = s[i];
       
        if (c == '0') return 0;
        if (c <= '2' && i+1 < s.size()){
            char d = s[i+1];
            decode[i] = c == '1' ? Decoding(s, i+1) + Decoding(s, i+2): (d > '6' ? Decoding(s, i+1) : Decoding(s, i+1) + Decoding(s, i+2));
        }
        else decode[i] = Decoding(s, i+1);
        return decode[i];
    }
};


int main(){
    Solution s;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("226") << endl;
    cout << s.numDecodings("0") << endl;
    cout << s.numDecodings("10") << endl;
    cout << s.numDecodings("100") << endl;
    cout << s.numDecodings("101") << endl;
    return 0;
}
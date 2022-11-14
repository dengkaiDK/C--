#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long N = 0, i;
        for (i = 0; N < k; ++i)
            N = isdigit(s[i]) ? N * (s[i] - '0') : N + 1;
        while (i--)
            if (isdigit(s[i]))
                N /= s[i] - '0', k %= N;
            else if (k % N-- == 0)
                return string(1, s[i]);
        return string("");
    }
};

int main(){
    Solution a;
    string s = "leet2code3";
    int k = 10;
    cout << a.decodeAtIndex(s, k) << endl;
    return 0;
}
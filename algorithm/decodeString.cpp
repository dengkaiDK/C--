#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;
        int num =0;
        string result = "";
        for (auto c : s)
        {
            if (c != char(']'))
            {
                if (char('0') <= c && c <= char('9')){
                    num = num * 10 + (c - char('0'));
                }
                else if (c == char('[')){
                    numstack.push(num);
                    strstack.push("[");
                    num = 0;
                }
                else {
                    strstack.push(string(1, c));
                }
            }
            else{
                string temp = "";
                while (strstack.top() != "[")
                {
                    temp = strstack.top() + temp;
                    strstack.pop();
                }
                strstack.pop();
                int n = numstack.top();
                numstack.pop();
                // replace
                for (int i=0; i<n; i++)
                {
                    strstack.push(temp);
                }
            }
        }
        while (!strstack.empty())
        {
            result = strstack.top() + result;
            strstack.pop();
        }
        return result;
    }
};

int main(void){
    string test = "3[a2[c]]";
    Solution s;
    cout << s.decodeString(test) << endl;
    return 0;
}
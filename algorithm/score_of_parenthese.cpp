#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<char, int>> a;
        int result = 0;
        int  num;
        for (auto c: s)
        {
            if (c == char('('))
            {
                a.push(make_pair(c, 0));
            }
            else{
                if (a.top().first == char('('))
                {
                    a.pop();
                    a.push(make_pair(c, 1));
                }
                else{
                    num = 0;
                    while (a.top().first != char('('))
                    {
                        num += a.top().second;
                        a.pop();
                    }
                    a.pop();
                    a.push(make_pair(c, 2*num));
                }
            }   
        }
        while (!a.empty())
        {
            result += a.top().second;
            a.pop();
        }
        return result;
    }
};

int main(void){
    Solution s;
    string str = "((((((())))()())))";
    cout << s.scoreOfParentheses(str) << endl;
    return 0;
}
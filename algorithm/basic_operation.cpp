// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
// 示例：
// 输入：s = "(1+(4+5+2)-3)+(6+8)"
// 输出：23
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
    public:
        int calculate(string s){
            stack<int> ops;
            int sign = 1;
            ops.push(sign);
            int ret = 0;
            int n = s.size();
            int i = 0;
            //O(n) time complexity
            //O(n) space complexity
            while (i < n){
                if (s[i] == ' '){
                    i++;
                }
                else if (s[i] == '+'){
                    sign = ops.top();
                    i++;
                }
                else if (s[i] == '-'){
                    sign = -ops.top();
                    i++;
                }
                else if (s[i] == '('){
                    ops.push(sign);
                    i++;
                }
                else if (s[i] == ')'){
                    ops.pop();
                    i++;
                }
                else{
                    int num = 0;
                    while (i <n && s[i]>='0' && s[i]<='9'){
                        num = num*10 + s[i] - '0';
                        i++;
                    }
                    ret += sign*num;
                }
            }
            return ret;
        };
};

int main(){
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(str) << endl;
    return 0;
}
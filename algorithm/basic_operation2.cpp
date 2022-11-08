// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
// 示例：
// 输入：s = "(1+(4+5*2)-3)/6+8"
// 输出：10
// 补充：加入了乘法和除法运算
#include <string>
#include <stack>
#include <iostream>

using namespace std;
class Solution{
public:
    int calculate(string s){
        int i = 0;
        return helper(s, i);
    }
    
    int helper(string s, int &i){
        stack<int> stk;
		int num = 0;
		char sign = '+'; //初始化符号为+
		for (; i < s.size(); i++)
		{
			// 当前字符是空格, 如果不是字符最后的位置, 直接跳过
			if (s[i] == ' ' && i != (int)s.size() - 1)
			{
				continue;
			}

			// 当前字符是数字
			else if (isdigit(s[i]))
			{
				num = 10 * num + (s[i] - '0');
			}

			// 当前字符是 '('
			else if (s[i] == '(')
			{
				i++;
				num = helper(s, i);
				i++;
			}

			// 第一种情况, 遇到 '+' , '-' , '*' , '/', ')' 需要进行运算
			// 第二种情况, 遇到字符串的尾部 (尾部可能是一个数字, 可能是 ')' , 也可能是' ' , 所以这两种情况之间有重叠)
			if (!isdigit(s[i]) || i == s.size() - 1)
			{
				int pre;
				switch (sign)
				{
				case '+':
					stk.push(num);
					break;
				case '-':
					stk.push(-num);
					break;
				case '*':
					pre = stk.top();
					stk.pop();
					stk.push(pre * num);
					break;
				case '/':
					pre = stk.top();
					stk.pop();
					stk.push(pre / num);
					break;
				}

				sign = s[i];
				num = 0;
                // 只有递归过程才会遇到 ')', 上面运算完了需要额外进行 break
                if (s[i] == ')')
				{
					break;
				}
			}
		}

		// 计算栈中所有元素的和
		int res = 0;
		while (!stk.empty())
		{
			res += stk.top();
			stk.pop();
		}

		return res;
    }
};


int main(){
    Solution s;
    string str = "(1+(4+5*2)-3)/6+8";
    cout << s.calculate(str) << endl;
    return 0;
}
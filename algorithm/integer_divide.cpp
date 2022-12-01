#include<iostream>
#include<limits>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        int q = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        if (dividend == INT_MIN){
            if(divisor == -1)
                return INT_MAX;
            else if(divisor == 1)
                return INT_MIN;
            else return ((divisor & 1) ==1) ? divide(dividend + 1, divisor) : divide(dividend >> 1, divisor >> 1);                                                       }
        if (divisor == INT_MIN) return 0;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        int temp, m;
        
        while (dividend >= divisor){
            temp = divisor, m = 1;
            while(temp  <  (dividend >> 1)){
                temp = temp << 1;
                m = m << 1;
            }
            dividend -= temp;
            q += m;
        }

        return sign * q;
    }
};


int main(){
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;
    cout << s.divide(-2147483648, -1) << endl;
    cout << s.divide(-2147483648, 1) << endl;
    cout << s.divide(-2147483648, 2) << endl;
    cout << s.divide(-2147483648, 3) << endl;
    return 0;
}
#include<iostream>
#include<limits>
#include<string>

using namespace std; 


class Solution {
public:
    int mAtoi(string s){
        int number = 0;
        int sign = 1;
        for(int i=0; i<s.size(); i++){
            //assume the string is valid

            if(s[i] == ' '){
                continue;
            }
            if(s[i] == '-'){
                sign = -1;
                if(s[i+1] < '0' || s[i+1] > '9')
                    break;
                continue;
            }
            if(s[i] == '+'){
                sign = 1;
                if(s[i+1] < '0' || s[i+1] > '9')
                    break;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                if(number > INT_MAX/10 || (number == INT_MAX/10 && s[i] - '0' > 7)){
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                number = number * 10 + (s[i] - '0');
                if(s[i+1] < '0' || s[i+1] > '9'){
                    break;
                }
            }
            else{
                break;
            }
    }
    return number * sign;
    }
};


int main(){
    Solution s;
    cout << s.mAtoi("    -") << endl;
    return 0;
}
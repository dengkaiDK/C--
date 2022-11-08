#include<iostream>
#include<deque>
using namespace std;

//global variable
int max_int = pow(2, 31) - 1;
int min_int = -pow(2, 31);

class Solution {
public:
    int reverse(int x) {
        deque<int> digits;

        while(x!= 0){
            digits.push_back(x%10); // -3 -2 -1 
            x = x/10;
        }
        
        for(deque<int>::iterator it = digits.begin(); it != digits.end(); it++){
            cout << *it << " ";
        }
        double result = 0;
        while(!digits.empty()){
            int temp = digits.front();
            result = 10 * result + temp;
            if (result > max_int || result < min_int){
                return 0;
            }
            digits.pop_front();
        }
        return result;
    }
};


int main(void){
    int x = -123;
    Solution r;
    cout << r.reverse(x) <<endl;
    return 0;
}
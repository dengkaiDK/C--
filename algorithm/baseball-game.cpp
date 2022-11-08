#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        map<string, int> m;
        m.insert(make_pair("C", 1));
        m.insert(make_pair("D", 2));
        m.insert(make_pair("+", 3));
        int elem, elem1, elem2;
        for(auto t: operations)
        {
            switch(m[t]){
                case 1:
                    s.pop();
                    break;
                case 2:
                    elem = s.top();
                    s.push(2*elem);
                    break;
                case 3:
                    elem1 = s.top();
                    s.pop();
                    elem2 = s.top();
                    s.push(elem1);
                    s.push(elem1 + elem2);
                    break;
                default:
                    elem = stoi(t);
                    s.push(elem);
                    break;
            }
            
        }
        int total_sum = 0;
        while(!s.empty()){
            int elem = s.top();
            total_sum += elem;
            s.pop();
        }
        return total_sum;
    }
};

int main(void){
    Solution s;
    vector<string> v = {"5","-2","4","C","D","9","+","+"};
    cout << s.calPoints(v) << endl;
    return 0;
}
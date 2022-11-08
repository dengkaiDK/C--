#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> p1;
    priority_queue<int, vector<int>, less<int>> p2;

    int bigger_than_w(vector<int> &nums, int w){
        int count = 0;
        for (auto i: nums){
            if (i > w){
                p1.push(i - w);
            }
            if (i < w){
                p2.push(i - w);
            }
            if (i == w){
                count++;
            }
        }
        count += p1.size();
        while(!p1.empty() && !p2.empty()){
            // get the minimum of positive value
            int resource = p1.top();
            if (resource + p2.top() >= 0){
                resource += p2.top();
                count ++;
                p2.pop();
                p1.pop();
                if (resource > 0){
                    p1.push(resource);
                }
            }
            else{
                p1.pop();
            }
        }
        return count;
    }

};

int main(void){
    Solution s;
    vector<int> numbers = {11, 9, 11, 9};
    int w = 10;
    cout << s.bigger_than_w(numbers, w) << endl;
    return 0;
}
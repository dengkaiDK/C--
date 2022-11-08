#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        bool found = false;
        int s3= INT_MIN;
        for(int i = nums.size() - 1; i>=0; i--)
        {
            if(nums[i] < s3)
                {
                    found = true;
                    break;
                }
            else{
                while(!s.empty() && nums[i] > s.top())
                {
                    s3 = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        
        return found;
    }
};

int main(void){
    Solution a;
    vector<int> nums = {3, 5, 0, 3, 4};
    cout << a.find132pattern(nums) << endl;
    return 0;
}
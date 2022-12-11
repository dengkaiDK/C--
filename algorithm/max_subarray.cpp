#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// DP solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(auto n : nums){
            sum = sum + n > 0 ? sum + n : 0;
            if (sum > max && sum != 0)
                max = sum;
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
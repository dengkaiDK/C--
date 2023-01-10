#include<iostream>
#include<vector>

using namespace std;

// description: Given an array of integers, every element appears three times except for one. Find that single one.

// O(n) time, O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum, odd, ans = 0;
        for(int i=0; i < 32; i++){
            sum = 0;
            odd = 0;
            for(int j =0; j < nums.size(); j++){
                if ((1 & nums[j]) != 0) odd++;
                nums[j] >>= 1;
                sum |= nums[j];
            }

            if( odd % 3 != 0) ans |= (1 << i);  
            if (sum == 0) break;
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
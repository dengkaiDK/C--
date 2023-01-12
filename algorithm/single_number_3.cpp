#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // O(1) space, O(n) time
    vector<int> singleNumber(vector<int>& nums) {
        int xord = 0;
        int result1 = 0, result2 = 0;
        int first_zero;

        for(int i=0; i< nums.size(); i++){
            xord ^= nums[i];
        }

        for(int i=0; i<32; i++){
            if ( (xord >> i) & 1){
                first_zero = i;
                break;
            }
        }

        for(int i=0; i < nums.size(); i++){
            if ( (nums[i] >> first_zero) & 1){
                result1 ^= nums[i];
            }
            else result2 ^= nums[i];
        }

        return {result1, result2};
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> result = s.singleNumber(nums);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}
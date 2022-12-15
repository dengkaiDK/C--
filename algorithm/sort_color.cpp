#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0, end = nums.size() - 1;
        while(start < end){
            if(nums[start] != 0){
                while (end >= 0 && nums[end] != 0) end--;
                if (end < start) break;
                int temp;
                temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
            else start++;
        }

        end = nums.size() - 1;
        while (start < end){
            if (nums[end] != 2){
                while (start <= end && nums[start] != 2) start++;
                if(start > end) break;
                int temp;
                temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
            else end--;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}